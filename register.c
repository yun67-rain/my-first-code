#include<stdio.h>

void cash_register(){
    int end=0;
    int price;
    int product=0,tax=0,sum=0,count=0;

    while(end==0){
        printf("\n商品の値段を入力してください（終了は0）:");
        scanf("%d",&price);
        if(price==0){
            end=1;
        }else if(price<0){
        printf("可能な数字を入力してください。\n");
        }else {
        product+=price;
        count++;
        }
    }

    int subtotal=product;
    int discount=500;
    if(product>=5000){
        subtotal-=discount;
        printf("割引金額：%d円\n",discount);
    }
    tax=subtotal*0.1;
    sum=subtotal+tax;

    printf("商品の点数：%d個\n",count);
    printf("小計：%d円\n",subtotal);
    printf("消費税：%d円\n",tax);
    printf("合計：%d円\n",sum);

}

int main(void){

    printf("いらっしゃいませ\n");
    printf("5000円以上お買い上げで、500円引きです。\n");

    cash_register();
    printf("ご利用ありがとうございました。\n");

    return 0;
    
}