#include<stdio.h>
#include<iostream>

int main(){
    int w[9][9];
    int d[9];
    int p[9];

    for(int i=0;i<9;i++){
        d[i]=1e9;
    }
    d[0]=0;
    p[0]=0;

    for(int i=0;i<9-1;i++){
        for(int a=0;a<9;a++){
            for(int b=0;b<9;b++){
                if((d[a]!=1e9) && (w[a][b]!=1e9)){
                    if(d[a]+w[a][b] < d[b]){
                        d[b]=d[a]+w[a][b];
                        p[b]=a;
                    }
                }
            }
        }
    }
    
    return 0;
}