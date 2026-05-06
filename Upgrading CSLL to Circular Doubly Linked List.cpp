// Write your code here
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next,*prev;
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};
class Cdll{
    Node *head;
    public:
    Cdll(){
        head=NULL;
    }
    void insertbegin(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            newnode->next=newnode;
            newnode->prev=newnode;
            head=newnode;
            return;
        }
        Node *tail=head->prev;
        newnode->next=head;
        newnode->prev=tail;
        tail->next=newnode;
        head->prev=newnode;
        head=newnode;
    }
    void insertend(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            newnode->next=newnode;
            newnode->prev=newnode;
            head=newnode;
            return;
        }
        Node *tail=head->prev;
        tail->next=newnode;
        newnode->prev=tail;
        newnode->next=head;
        head->prev=newnode;
    }
    void deletebegin(){
        if(head==NULL){
            return;
        }
        if(head->next==head){
            delete head;
            head=NULL;
            return;
        }
        Node *tail=head->prev;
        Node *temp=head;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        delete temp;
    }
    void deleteend(){
        if(head==NULL){
            return;
        }
        if(head->next==head){
            delete head;
            head=NULL;
            return;
        }
        Node *tail=head->prev;
        Node *newtail=tail->prev;
        newtail->next=head;
        head->prev=newtail;
        delete tail;
    }
    void displayforward(){
        if(head==NULL){
            return;
        }
        cout<<"Forward: ";
        Node *temp=head;
        do{
            cout<<temp->data<<" <-> ";
            temp=temp->next;
        }while(temp!=head);
        cout<<"(HEAD)"<<endl;
    }
    void displaybackward(){
        if(head==NULL){
            return;
        }
        cout<<"Backward: ";
        Node *tail=head->prev;
        Node *temp=tail;
        do{
            cout<<temp->data<<" <-> ";
            temp=temp->prev;
        }while(temp!=tail);
        cout<<"(HEAD)"<<endl;
    }
};
int main(){
    Cdll lst;
    int m=0,n;
    while(m!=7){
        cin>>m;
        if(m==1){
            cin>>n;
            lst.insertbegin(n);
        }
        else if(m==2){
            cin>>n;
            lst.insertend(n);
        }
        else if(m==3){
            lst.deletebegin();
        }
        else if(m==4){
            lst.deleteend();
        }
        else if(m==5){
            lst.displayforward();
        }
        else if(m==6){
            lst.displaybackward();
        }
    }
    return 0;
}