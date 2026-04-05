#include<stdio.h>
#include<string.h>

struct Student{
    char name[20];
    int id;
    int score;
};

void print_student(struct Student s){
    printf("==学生情報==\n");
    printf("名前：%s\n",s.name);
    printf("番号：%d\n",s.id);
    printf("点数：%d\n",s.score);

    if(s.score>=60){
        printf("判定：合格\n");
    }else{
        printf("判定：不合格. 次は頑張ろう\n");
    }
}

int main(void){
    struct Student s1;

    printf("名前を入力してね：");
    scanf("%s",s1.name);
    printf("学籍番号を入力してね：");
    scanf("%d",&s1.id);
    printf("点数を入力してね：");
    scanf("%d",&s1.score);

    print_student(s1);

    return 0;
}