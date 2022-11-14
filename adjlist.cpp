#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

//vector 可以想成一個可以改變大小的陣列
void addedge(vector<int> *adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printadjlist(vector<int> *adj,int n){
    for(int i=0;i<n;i++){
        cout<<"vertex "<< i <<" adj vertex : ";
        for(auto v:adj[i]){
            cout << v << " -> ";
        }
        cout << endl;
    }
}
int main(){
    int v=5;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,0,3);
    addedge(adj,1,4);
    addedge(adj,2,4);
    addedge(adj,3,4);
    addedge(adj,3,1);
    printadjlist(adj,v);
    return 0;
}