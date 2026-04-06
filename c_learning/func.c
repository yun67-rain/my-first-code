#include<stdio.h>

int add_tax(int price){
    return price*1.1;
}

int main(void){
    int money;
    printf("税抜き価格を入力：");
    scanf("%d",&money);

    int total=add_tax(money);

    printf("税込価格は%d円です\n",total);
    return 0;
}