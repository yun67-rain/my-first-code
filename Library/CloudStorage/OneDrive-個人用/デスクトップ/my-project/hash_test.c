#include<stdio.h>
#include<string.h>

unsigned long generate_hash(char *str){
    unsigned long hash=5381;
    int c;
    while((c=*str++)){
        hash=((hash<<5)+hash)+c;
    }
    return hash;
}

int main(){
    char password[20];
    unsigned long saved_hash;

    printf("【登録】新しいパスワードを入力:");
    scanf("%s",password);
    saved_hash=generate_hash(password);
    printf("保存されたハッシュ値:%lu\n\n",saved_hash);

    char input[20];
    printf("【認証】パスワードを入力してログイン:");
    scanf("%s",input);

    if(generate_hash(input)==saved_hash){
        printf("認証成功。ハッシュ値が一致しました。\n");
    }else{
        printf("認証失敗。ハッシュ値が異なります。\n");
    }
    return 0;
}