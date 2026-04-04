#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    char id[9];
    int success=0;
    while(success==0){ 
    printf("\n[Caution]\n");       
    printf("Start with \"A\"or \"a\" .\n");
    printf("Contain at least one digit.");
    printf("\nCreate your ID(8 chars):");
    scanf("%s",id);

    int error_count=0;

    if(strlen(id)!=8){
        printf("Error:8 characters required.\n");
        error_count++;
    }
    if(id[0]!='A'&&id[0]!='a'){
        printf("Error:ID must start with A.\n");
        error_count++;
    }

    int has_digit=0;
    for(int i=0;id[i]!='\0';i++){
        if(isdigit(id[i])){
            has_digit=1;
            break;
        }
    }
    if(has_digit==0){
        printf("Error:Must contain at least one digit.\n");
        error_count++;
    }

    if(error_count==0){
            success=1;
    }
    }

    printf("ID Acceped!\n");

    return 0;
}