#include<stdio.h>
#include<string.h>

struct Account{
    char holder[20];
    long long balance;
    char pin[5];
    char logs[5][64];
    int log_count;
};

int check_pin(char *correct){
    char input[5];
    for(int i=0;i<3;i++){
    printf("\n4桁の暗証番号を入力してください（残り%d回）：\n",3-i);
    scanf("%s",input);
        if(strcmp(input,correct)==0){
        printf("認証に成功しました\n");
        return 0;
        }
        printf("番号が違います。\n");
    } 
    printf("３回間違えました。アカウントをロックします。\n");
    return 1;       
}

void deposit(struct Account *a){
    long long amount;
    printf("入金する金額を入力:");
    scanf("%lld",&amount);
    if(amount>0){
        a->balance+=amount;
        printf("入金完了:%lld円\n",amount);
        printf("残高:%lld\n",a->balance);
        sprintf(a->logs[a->log_count%5],"入金完了:%lld円\n",amount);
        a->log_count++;
    }else{
        printf("エラー：無効な数字です。\n");
    }
}

void withdraw(struct Account *a){
    long long amount;
    printf("出金する金額を入力：");
    scanf("%lld",&amount);
    if(amount>a->balance){
        printf("エラー：残高不足です（残高:%lld円）\n",a->balance);
    }else if(amount<=0){
        printf("エラー：無効な数字です。\n");
    }else{
        a->balance-=amount;
        printf("出金完了:%lld円\n",amount);
        printf("残高:%lld\n",a->balance);
        sprintf(a->logs[a->log_count%5],"出金完了:%lld円\n",amount);
        a->log_count++;
    }
}

void transfer(struct Account *a,struct Account *b,int num_costomers){
    long long money;
    int success=0;
    int to_idx;

    printf("\n---振込手続き---\n");

    for(int i=0;i<num_costomers;i++){
        if(&b[i]!=a){
            printf("[%d]%s様\n",i,b[i].holder);
        }
    }

    printf("振込先を選択してください:\n");
    scanf("%d",&to_idx);

    if(to_idx<0||to_idx>=num_costomers||&b[to_idx]==a){
        printf("エラー：無効な相手です。\n");
        return;
    }
    
    while(success==0){
        printf("\n残高は%lld円です。\n手数料は210円です。\n",a->balance);
        printf("振込金額を入力(中断は0）：");
        scanf("%lld",&money);
            if(money<0){
            printf("エラー：0円以下の振込はできません。\n");
            }else if(money==0){
            return;
            }else if(money+210>a->balance){
            printf("エラー：残高不足です。\n");
            }else{
            a->balance-=(money+210);
            b[to_idx].balance+=money;
            printf("振込完了:%lld円\n",money);
            printf("残高:%lld\n",a->balance);
            sprintf(a->logs[a->log_count%5],"振込完了:%lld円(内手数料210円)\n",money+210);
            a->log_count++;
            success=1;
        }
    }
}

void change_pin(struct Account *a){
    char now[5],change1[5],change2[5];
    int success=0;
    int success2=0;

    while(success==0){
    printf("\n現在の4桁の暗証番号を入力してください(中断は0）：\n");
    scanf("%s",now);

    if(strcmp(now,"0")==0)return;

    if(strcmp(now,a->pin)==0){
        success=1;
        while(success2==0){
        printf("\n新しい4桁の暗証番号を入力してください：\n");
        scanf("%s",change1);
        if(strcmp(change1,a->pin)==0){
            printf("同じ暗証番号には変更できません。\n");
        }else if(strlen(change1)!=4){
            printf("4桁の暗証番号を入力してください。\n");
        }else{
            printf("確認のためもう一度入力してください：\n");
            scanf("%s",change2);
            if(strcmp(change1,change2)==0){
             strcpy(a->pin,change1);
             printf("暗証番号の変更が完了しました。\n");
             success2=1;
            }else{
            printf("エラー：番号が一致しません\n");
        }
        }
        }
    }else{
        printf("番号が違います。もう一度試してください。\n");
    }
    }

}

void pass(struct Account *a){
    printf("---取引履歴（過去５件）---\n");
    if(a->log_count==0){
        printf("取引履歴はありません\n");
        return;
    }else{
        for(int i=0;i<a->log_count;i++){
        printf("%d:%s\n",i+1,a->logs[i]);
        }
    }
}

int main(void){
    struct Account bank[3]={{"Yunno",1000,{"1234"},{""},0},
                            {"Sato",500,{"5678"},{""},0},
                            {"Tanaka",2000,{"0000"},{""},0}};
    int choice;
    int num;
    struct Account *current_user;

    printf("口座番号を選んでください。\n[0]Yunno [1]Sato [2]Tanaka:\n");
    scanf("%d",&num);
    current_user=&bank[num];
    if(check_pin(current_user->pin)==1){
        return 1;
    }

    printf("ようこそ%s様\n",current_user->holder);

    while(1){
        printf("\n---メニュー---\n");
        printf("1:残高確認 2:入金 3:出金 4:振込 5:暗証番号変更 6:取引履歴 7:終了\n");
        scanf("%d",&choice);

        if(choice==7){
            printf("ご利用ありがとうございました\n");
            break;
        }
        switch(choice){
            case 1:
            printf("現在の残高は%lld円です。\n",current_user->balance);
            break;
            case 2:
            deposit(current_user);
            break;
            case 3:
            withdraw(current_user);
            break;
            case 4:
            transfer(current_user,bank,3);
            break;
            case 5:
            change_pin(current_user);
            break;
            case 6:
            pass(current_user);
            break;
            default:
            printf("1~7の番号を入力してください\n");
            break;
        }
    }
    return 0;
}