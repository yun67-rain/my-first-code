#include <stdio.h>
#include <stdbool.h>
#define maxsize 100

typedef struct{
    int value[maxsize];
    int size;
}BAG;

BAG insert(int e,BAG B){
  if(B.size<maxsize-1){
    B.size=B.size+1;
    B.value[B.size]=e;
  } 
  return B;
}

int search(int e,BAG *B){
  int i=0;
  while((B->value[i]!=e)&&(i<=B->size))
  i=i+1;
  if(i<=B->size) return i;
  else return -1;  
}

BAG delete(int e,BAG B){
    int i;
    i=search(e,&B);
    if(i!=-1){
        B.value[i]=B.value[B.size];
        B.size=B.size-1;
    }
    return B;
}

BAG empty(){
BAG temp;
temp.size=-1;
return temp;
}

bool is_element(int e,BAG *B){
int i;
i=search(e,B);
if(i==-1){
  return false;
}else{
  return true;
}
}

bool is_empty(BAG *B){
if (B->size==-1){
  return true;
}else{
  return false;
}
}

int main(void){
    BAG B=empty();;
    printf("is empty?:%d\n",is_empty(&B));
    B=insert(3,B);
    B=insert(2,B);
    B=insert(1,B);
    printf("is empty?:%d\n",is_empty(&B));;
    B=delete(3,B);
    printf("%d is element?:%d\n",3,is_element(3,&B));
    printf("%d is element?:%d\n",2,is_element(2,&B));
    printf("%d is element?:%d\n",1,is_element(1,&B));
    return 0;
}