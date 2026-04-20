#include<stdio.h>

struct StudentStruct{
    int i;
    double d;
};

union StudentUnion{
    int i;
    double d;
};

int main(){
    struct StudentStruct s_data;
    union StudentUnion u_data;

    printf("Struct size:%lu\n",sizeof(s_data));
    printf("Union size:%lu\n",sizeof(u_data));

    printf("Struct -iのアドレス:%p\n",(void*)&s_data.i);
    printf("Struct -dのアドレス:%p\n",(void*)&s_data.d);
    printf("Union -iのアドレス:%p\n",(void*)&u_data.i);
    printf("Union -dのアドレス:%p\n",(void*)&u_data.d);

    u_data.i=100;
    u_data.d=0.01;
    printf("Union -dの値の変化:%d\n",u_data.i);   
}