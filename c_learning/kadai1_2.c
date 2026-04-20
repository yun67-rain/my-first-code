#include<stdio.h>

struct Character{
    int level;
    int hp;
};

int levelUp_Value(struct Character a){
    a.level+=10;
    a.hp+=100;
}

int levelUp_Ref(struct Character *p){
    p->level+=10;
    p->hp+=100;
}

int main(){
    struct Character s;
    s.level=1;
    s.hp=400;

    levelUp_Value(s);
    printf("(値渡し)の時のレベル:%d\n",s.level);
    printf("(値渡し)の時のHP:%d\n",s.hp);

    levelUp_Ref(&s);
    printf("(参照渡し)の時のレベル:%d\n",s.level);
    printf("(参照渡し)の時のHP:%d\n",s.hp);
}