#include<stdio.h>

int main(void){
    int x,y,z;
    printf("数字を３つ入力してください：");
    scanf("%d %d %d",&x,&y,&z);

    if(x>=y&&x>=z){
        printf("%dが最大である",x);
    }else if (y>=x&&y>=z){
        printf("%dが最大である",y);
    }else{
        printf("%dが最大である",z);
    }
}