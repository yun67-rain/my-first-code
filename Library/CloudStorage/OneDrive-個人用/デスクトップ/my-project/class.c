#include<stdio.h>
#include<string.h>

struct Student{
    char name[20];
    int score;
};

int main(void){
    struct Student class_a[3];

    for(int i=0;i<3;i++){
        printf("%d人目の名前：",i+1);
        scanf("%s",class_a[i].name);
        printf("%d人目の点数：",i+1);
        scanf("%d",&class_a[i].score);
    }

    printf("\n---成績一覧---\n");
    for(int i=0;i<3;i++){;
    printf("%sさん：%d点\n",class_a[i].name,class_a[i].score);
    }
}
