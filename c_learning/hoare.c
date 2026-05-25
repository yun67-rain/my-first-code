#include<stdio.h>

void change(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int hoare(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low-1;
    int j=high+1;

    while(1){
        do{i++;}while(arr[i]<pivot);
        do{j--;}while(arr[j]>pivot);
        if(i>=j)return j;
        change(&arr[i],&arr[j]);
    }
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int j=hoare(arr,low,high);

        quicksort(arr,low,j);
        quicksort(arr,j+1,high);
    }
}
int main(){
    int arr[]={4,2,5,1,3};
    int range=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,range-1);

    printf("ソート後:");
    for(int i=0;i<range;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}