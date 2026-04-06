#include<stdio.h>
#include<stdlib.h>//乱数を使うために必要
#include<time.h>//協定世界時からの差の時間を使うために必要
#include<string.h>

#ifdef _WIN32
    #include<windows.h>
    #define sleep_ms(ms) Sleep(ms)//windowsはミリ指定
#else
    #include<unistd.h>
    #define sleep_ms(ms) usleep(ms*1000)//Mac/Linuxはマイクロ秒なので1000秒    
#endif

#define RESET "\033[m"
#define TITLE "\033[1;36m"//シアン・太字
#define P1_CLR "\033[1;35m"//マゼンタ・太字
#define P2_CLR "\033[1;33m"//黄色・太字
#define ALERT "\033[30;43m"//背景黄・文字黒・点滅
#define SUCCESS "\033[1;32;5m"//緑・点滅

void show_title(){
    printf(TITLE"==============================\n");
    printf("   N U M B E R  H A C K E R\n");
    printf("=============================="RESET"\n\n");
}

void print_warning(char *msg){
    //文字列は代入することができないため、住所の＊を使って、最初の文字の住所を明らかにする
    printf(ALERT"%s"RESET"\n",msg);
}

int mode_select(){
    int mode;
    printf("MODES:\n[1] VS COMPUTER (SOLO)\n[2] VS HUMAN (2P)\n[3] REVENGE HACKING (VS AI)\n");
    while(1){
        printf("SELECT MODE:");
        if(scanf("%d",&mode)!=1||mode<1||mode>3){
            print_warning("!!! ERROR:1と2のどちらかを選べ !!!");
            while(getchar()!='\n');
        }else{
            return mode;
        }
    }
}

int level_select(){
    printf("\nLEVEL SELECT:挑戦するレベルを選べ\n");
    printf("LEVEL1:0~50(easy)\nLEVEL2:0~100(medium)\nLEVEL3:0~1000(hard)\n");
    int level;
    int range;
    while(1){
        printf("LEVEL:");
        if(scanf("%d",&level)!=1||level<1||level>3){
            print_warning("!!! ERROR:1~3のうちから選べ !!!");
            while(getchar()!='\n');
        }else{
            if(level==1)range=50;
            else if(level==2)range=100;
            else range=1000;
            break;
        }
    }
    return range;
}

void boot_archangel(){
    printf(TITLE"\n[SYSTEM] AI [ARCHANGEL] 起動中..."RESET"\n");
    sleep_ms(800);

    printf("防壁(ファイアウォール)を構築しています");
    for(int i=0;i<3;i++){
        printf(".");
        fflush(stdout);//stdout(標準出力)は溜め込み場所、fflushはそれを吐き出せという命令
        sleep_ms(600);
    }

    printf(SUCCESS"\n[!] 暗号コードの生成が完了しました。"RESET"\n");
    sleep_ms(500);
}


void clear_screen(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int get_secret_number(int range){
    int s;
    while(1){
        printf(P1_CLR"\n[Player 1]"RESET"ターゲット数値を設定せよ(0~%d):",range);//scanf("%d",$s)!=1は送られたものが数字ではないときを指す(1は偽であるという意味)
        if(scanf("%d",&s)!=1||s<0||s>range){
            print_warning("!!! INVALID INPUT :範囲内の数値を入力せよ !!!");
            //sに入ってしまった文字列をバッファクリアする
            //改行コードが来るまで、間違って入力されたものを消去する
            while(getchar()!='\n');
        }else{
            break;
        }
    }
    clear_screen();
    return s;
}

int start_hacking(int secret,int range,int max_try){
    int guess;
    int count=0;

    printf(P2_CLR">>侵入開始。ターゲットコードを解析せよ(0~%d)\n"RESET,range);
    
    while(count<max_try){
        if(count<=6){
            printf("\nATTEMPT[%d/%d]>",count+1,max_try);
        }else{
           printf("\nATTEMPT[\033[1;31m%d"RESET"/%d]>",count+1,max_try); 
        }
        if(scanf("%d",&guess)!=1){
            print_warning("!!! ERROR:数値以外は受け付けない !!!");
            while(getchar()!='\n');
            //今回の周回だけ、あとの全部をすっ飛ばして、次の周回の最初に戻るという命令
            continue;
        }
        count++;

        if(guess==secret) return 1;//成功

        if(guess<secret){
            printf(">>"P2_CLR"TOO LOW"RESET"(解析値が低すぎます)\n");
            if(abs(guess-secret)<=5){
                print_warning("!!! CRITICAL:ターゲットに極めて接近 !!!");
            }
        }else{
            printf(">>"P2_CLR"TOO HIGH"RESET"(解析値が高すぎます)\n");
            if(abs(guess-secret)<=5){
                print_warning("!!! CRITICAL:ターゲットに極めて接近 !!!");
            }
        }
    }
    return 0;//失敗
}

void revenge_hacking(int range){
    int low=0;
    int high=range;
    int mid;
    char responce;

    printf("\n"TITLE">>>[SYSTEM] 逆転モード起動: あなたが数値を決めてください。"RESET"\n");
    printf("私はそれを解析します。準備ができたらENTERキーを押してください...");
    while(getchar()!='\n');//入力待ち

    while(low<=high){
        printf("\nARCHANGELが思考中");
        for(int i=0;i<3;i++){
            printf(".");
            fflush(stdout);
            sleep_ms(1000);
        }
        mid=(low+high)/2;
        printf("\nARGHANGELの予測:"P2_CLR"%d"RESET"\n",mid);
        printf("判定(h:高い,l:低い,c:正解):");
        scanf(" %c",&responce);

        if(responce=='c'){
            printf(SUCCESS"\n[!] ターゲットを特定しました。解析完了。"RESET"\n");
            break;
        }else if(responce=='h'){
            high=mid-1;
        }else if(responce=='l'){
            low=mid+1;
        }else{
            print_warning("!!! 入力エラー: h,l,c のいずれかを入力せよ !!!");
        }
    }
}


int main(void){
    int mode;
    int secret;
    int max_try=10;
    int range;
    int result;

    show_title();
    mode=mode_select();
    range=level_select();
    if(mode==1){
        boot_archangel();
        srand(time(NULL));
        secret=rand()%(range+1);
    }else if(mode==3){
        revenge_hacking(range);
        return 0;
    }else{
    secret=get_secret_number(range);
    clear_screen();
    printf(">>>[SYSTEM] 侵入者への防壁を展開しました。\n");
    }

    time_t start=time(NULL);

    result=start_hacking(secret,range,max_try);

    time_t end=time(NULL);
    double diff=difftime(end,start);

   if(result){
    printf(SUCCESS"\n*** SYSTEM HACKED SUCCESSFULLY ***"RESET"\n");
    printf(SUCCESS"\n[CLEAR] 突破タイム:%.0f秒"RESET"\n",diff);
   }else{
    printf("\033[1;31m\n\n[!]MISSION FAILED. ACCESS DENIED. \033[m\n");
    printf("正解は[%d]でした。\n",secret);
   }

    return 0;
}