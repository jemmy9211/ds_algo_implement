#include<iostream>
#include<stdio.h>
#include <algorithm>    // std::swap
using namespace std;
int arr[11]={1,3,5,4,6,13,10,9,8,15,17};
//complete tree
//            1
//         /     \
//        3       5
//      /  \     / \
//     4    6   13  10
//    / \  / \  
//   9  8 15 17
void heapify(int* arr,int n,int i){
    int root=i;
    int l=i*2+1;
    int r=i*2+2;
    if(l<n && arr[l]>arr[root]){
        root=l;
    }

    if(r<n && arr[r]>arr[root]){
        root=r;
    }

    if(root!=i){
        swap(arr[i],arr[root]);
        heapify(arr,n,root);
    }
}

void buildheap(int *arr,int n){
    int lastparent=(n/2)-1;
    for(int i=lastparent;i>=0;i--){
        heapify(arr,n,i);
    }
}
void printheap(int *arr,int n){
    int next=1;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
        if(i+1==next){
            cout<< endl;
            next=next*2+1;
        }
    }
    cout<<endl;
}
int main(){
    int n=11;
    buildheap(arr,n);
    printheap(arr,n);

}