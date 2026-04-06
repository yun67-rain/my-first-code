#include<stdio.h>

int main(void){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            int num=i*j;
            printf("%2d",num);
        }
        printf("\n");
    }
}