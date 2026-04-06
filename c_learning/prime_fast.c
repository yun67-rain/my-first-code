#include<stdio.h>

int is_prime_fast(long long n){
    if(n<=1)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;
//掛け算は途中から同じ形になるから√numまでで良い
    for(long long i=3;i*i<=n;i+=2){
        if(n%i==0)return 0;
    }
    return 1;
}

int main(void){
    long long num;
    printf("数字を入力して：");
    scanf("%lld",&num);

    if(is_prime_fast(num)){
        printf("%lldは素数です",num);
    }else{
        printf("%lldは素数ではありません",num);
    }
}