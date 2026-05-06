// Write your code here
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
class Doublylinkedlist{
    public:
    Node *head;
    Doublylinkedlist(){
        head=NULL;
    }
    void insertend(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
        head=newnode;
        return;
        }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    }
    void insertbegin(int val){
        Node *newnode=new Node(val);
        if(head!=NULL){
            head->prev=newnode;
            newnode->next=head;
        }
        head=newnode;
    }
    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    int n,m;
    cin>>n;
    Doublylinkedlist dlst;
    for(int i=0;i<n;i++){
        cin>>m;
        dlst.insertend(m);
    }
    int val;
    cin>>val;
    dlst.insertbegin(val);
    dlst.display();
    return 0;
}
