#include<iostream>
#include<stdio.h>
using namespace std;

struct Node{
     int data;
     struct Node* next;
     Node(int data){
        this->data=data;
        this->next=NULL;
     }
};

struct LinkedList{
    Node* head;
    LinkedList(){
        this->head=NULL;
    }
    void push(int data){
        Node* tep=new Node(data);
        tep->next=head;
        head=tep;
    }
    void print(){
        Node* tep=head;
        while(tep!=NULL){
            cout<< tep->data << " ";
            tep=tep->next;
        }
        cout<<endl;
    }
    void invert(){
        Node* current=head;
        Node* pre=NULL;
        Node* next=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=pre;
            pre=current;
            current=next;
        }
        head=pre;
    }

};

int main(){
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    list.print();
    list.invert();
    list.print();

    return 0;
}