#include<stdio.h>

int main(void){
    int scores[5];
    int sum=0;

    printf("5人の点数を入力してね：\n");

    for(int i=0;i<5;i++){
        printf("%d人目：",i+1);
        scanf("%d",&scores[i]);
        sum+=scores[i];
    }

    double average=(double)sum/5;

    printf("合計点は%d点、平均点は%.1f点です\n",sum,average);

    return 0;
}