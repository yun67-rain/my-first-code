#include<stdio.h>

int main(void){
    int money,rest;
    printf("所持金を入力してください:");
    scanf("%d",&money);

    if(money>=1500){
        rest=money-1500;
        printf("購入できます！残高は%d円です",rest);
    }else{
        rest=1500-money;
        printf("お金が足りません。あと%d円必要です",rest);
    }
}