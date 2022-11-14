#include<stdio.h>
#include<algorithm>

int main(){
    int arr[10]={2,44,55,23,12,76,0,77,45,89};
    std::sort(arr,arr+10);
    int target;
    scanf("%d",&target);
    int l,r,m;
    l=0;
    r=9;
    while(l<=r){
        m=(l+r)/2;
        if(arr[m]>target){
            r=m-1;
        }else if(arr[m]<target){
            l=m+1;
        }else if(arr[m]==target){
            printf("found %d in position: %d\n",arr[m],m);
            break;
        }

    }

    return 0;
}