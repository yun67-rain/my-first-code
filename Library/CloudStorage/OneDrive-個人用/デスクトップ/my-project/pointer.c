#include<stdio.h>

int main(void){
    int snack=100;
    int *p;

    p=&snack;

    printf("中身：%d\n",snack);
    printf("住所（＆をつける）：%p\n",&snack);
    printf("ポインタpが持っている住所：%p\n",p);
    printf("ポインタpが指してる先の中身：%d\n",*p);

    return 0;
}