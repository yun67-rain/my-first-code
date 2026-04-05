#include<stdio.h>

int main(void){
   int x;
   printf("数字を入力して：");
   scanf("%d",&x);
   
   if(x%2==0){
    printf("%dは偶数です",x);
   }else{
    printf("%dは奇数です",x);
   }
}