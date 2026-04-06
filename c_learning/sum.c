#include<stdio.h>

int main(void){
    int n;
    int total=0;

    printf("1からどこまで足しますか:");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        total+=i;
    }

    printf("1から%dまでの合計は%dです\n",n,total);
    return 0;
}