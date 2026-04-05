#include<stdio.h>

struct Student{
    char name[20];
    int score;
};

int is_passed(int s){
    if(s>=60)return 1;
    return 0;
}

int main(void){
    struct Student class_a[2];

    for(int i=0;i<2;i++){
        printf("%d人目の名前：",i+1);
        scanf("%s",class_a[i].name);
        printf("点数：");
        scanf("%d",&class_a[i].score);
    }

    printf("\n---合格者一覧---\n");
    for(int i=0;i<2;i++){
          if(is_passed(class_a[i].score)){
            printf("%sさん、おめでとう\n",class_a[i].name);
          }  
    }
    return 0;
}