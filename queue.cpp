#include<iostream>
#include<stdio.h>
using namespace std;
//===================================只能用array n-1格
int q[5];
int rear=0;
int front=0;
void enqueue1(int* q,int item){
    int prerear=rear;
    rear=(rear+1)%5;
    if(rear==front){
        rear=prerear;
        cout<<"queue is full"<<endl;
    }else{
        q[rear] = item;
    }
}
void dequeue1(int* q){
    if(front==rear){
        cout<<"queue is empty"<<endl;
    }else{
        front=(front+1)%5;
        int item=q[front];
        cout<<"dequeued item is "<<item<<endl;
    }
}
//===================================可以用n格
int tag=0;
void enqueue2(int* q,int item){
    if(rear==front && tag==1){
        cout<<"queue is full"<<endl;
    }else{
        rear=(rear+1)%5;
        q[rear]=item;
        if(rear==front) tag=1;
    }
}
void dequeue2(int* q){
    if(front==rear && tag==0){
        cout<<"queue is empty"<<endl;
    }else{
        front=(front+1)%5;
        int item=q[front];
        if(front==rear) tag=0;
        cout<<"dequeued item is "<<item<<endl;
    }
}
void printqueue(int* q){
    cout<<"front is "<<front<<" rear is "<<rear<<endl;
    cout<< "queue content is ";
    for(int i=0;i<5;i++){
        cout << q[front] << " ";
        front=(front+1)%5;
    }
    cout<<endl;
}
//===================================linkedlist array
struct Node{
    int value;
    struct Node* next;
    Node(int data){
        this->value=data;
        this->next=NULL;
    }
};
Node* rearlist=NULL;
Node* frontlist=NULL;
Node* qlist=NULL;
void enqueuelist(Node* qlist,int item){
    Node* t=new Node(item);
    t->value=item;
    t->next=NULL;
    if(frontlist==NULL){
        frontlist=t;
    }else{
        rearlist->next=t;
    }
    rearlist=t;
}
void dequeuelist(Node* qlist){
    if(frontlist==NULL){
        cout<<"queue is empty"<<endl;
    }else{
        Node* t=frontlist;
        int item=frontlist->value;
        frontlist=frontlist->next;
        free(t);
        cout<<"dequeued item is "<<item<<endl;
    }
    
}
void printlist(Node* qlist){
    cout<<"List content is : ";
    Node* s=frontlist;
    while(s!=NULL){
        cout<<s->value<<" ";
        s=s->next;
    }
    cout<<endl;
}

int main(){
    cout<<"========================"<<endl;
    cout<<"use n-1 size of array to implemnet queue: "<<endl;
    enqueue1(q,1);
    enqueue1(q,2);
    enqueue1(q,3);
    enqueue1(q,4);
    enqueue1(q,5);
    printqueue(q);
    dequeue1(q);
    dequeue1(q);
    dequeue1(q);
    printqueue(q);
    cout<<"========================"<<endl;
    cout<<"use n size of array to implemnet queue: "<<endl;
    front=0;
    rear=0;
    enqueue2(q,1);
    enqueue2(q,2);
    enqueue2(q,3);
    enqueue2(q,4);
    enqueue2(q,5);
    printqueue(q);
    dequeue2(q);
    dequeue2(q);
    dequeue2(q);
    printqueue(q);
    cout<<"========================"<<endl;
    cout<<"use linkedlist to implemnet queue: "<<endl;
    enqueuelist(qlist,1);
    enqueuelist(qlist,2);
    enqueuelist(qlist,3);
    enqueuelist(qlist,4);
    dequeuelist(qlist);
    dequeuelist(qlist);
    printlist(qlist);

    return 0;
}