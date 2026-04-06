#include<stdio.h>
int is_prime(int num){
    if(num<=0)return 0;

    for(int i=2;i<num;i++){
    if(num%i==0){
        return 0;
    }
    }   
    return 1;
}
int main(void){
    int n;
    printf("数字を入力してください：");
    scanf("%d",&n);

    if(is_prime(n)){
        printf("%dは素数です",n);
    }else{
        printf("%dは素数ではありません",n);
    }
    return 0;
}