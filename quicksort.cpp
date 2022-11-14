#include<stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int *arr,int left,int right){
    if(left >= right){
        return;
    }

    int pivot=arr[left];
    int i=left;
    int j=right;
    while(i < j){
        while((i<j) && (arr[j]>pivot)){
            j--;
        }
        while((i<j) && (arr[i]<=pivot)){//
            i++;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }

    arr[left]=arr[i];
    arr[i]=pivot;
    quicksort(arr,left,i-1);
    quicksort(arr,i+1,right);
}

int main(){
    int arr[10]={2,44,55,13,12,76,0,77,45,89};
    quicksort(arr,0,9);
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}