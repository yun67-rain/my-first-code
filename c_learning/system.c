#include<stdio.h>

struct PrimeRecord{
    char name[20];
    long long prime;
};

int check_prime(long long n){
    if(n<=1)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;

    for(long long i=3;i*i<=n;i+=2){
        if(n%i==0)return 0;
    }
    return 1;
}

void invalidate_record(long long *p){
    *p=-1;
}

int main(void){
    struct PrimeRecord data[2];

    for(int i=0;i<2;i++){
        printf("%d人目の名前を入力してください：",i+1);
        scanf("%s",data[i].name);
        printf("発見した素数を入力してください：");
        scanf("%lld",&data[i].prime);
    }

    printf("\n--巨大素数カルテ登録--\n");
    for(int i=0;i<2;i++){
        printf("%d人目の研究員名：%s\n",i+1,data[i].name);
        printf("発見した数字：%lld\n",data[i].prime);
        printf("\n");
    }
    
    printf("\n--判定結果--\n");
    for(int i=0;i<2;i++){
        if(check_prime(data[i].prime)==0){
            printf("%sさんの数字は素数ではありませんでした。レコードを無効化します。\n",data[i].name);
            invalidate_record(&data[i].prime);
        }
    }

    printf("\n--最終カルテ一覧--\n");
    for(int i=0;i<2;i++){
        printf("[研究員：%s]発見した素数：%lld\n",data[i].name,data[i].prime);
    }
    
}