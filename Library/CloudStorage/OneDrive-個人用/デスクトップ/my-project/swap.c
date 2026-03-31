#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(void){
    int x=10,y=20;
    printf("入れ替え前：x=%d,y=%d\n",x,y);

    swap(&x,&y);

    printf("入れ替え後：x=%d,y=%d",x,y);
    return 0;
}