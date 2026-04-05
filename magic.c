#include<stdio.h>

void reset_score(int *p){
    *p=0;
}

int main(void){
    int score=100;
    printf("リセット前：%d点\n",score);

    reset_score(&score);
    printf("リセット後：%d点\n",score);
    return 0;
}