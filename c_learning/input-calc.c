#include<stdio.h>

int main(void){
    int x,y,result;

    printf("１つ目の数字を入力してね：");
    scanf("%d",&x);

    printf("２つ目の数字を入力してね：");
    scanf("%d",&y);

    result=x*y;

    printf("入力された%dと%dを掛け算すると、答えは%dです",x,y,result);

    return 0;
}