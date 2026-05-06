// Write your code here
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class Crclrlst{
    public:
    Node* head;
    Crclrlst(){
        head=NULL;
    }
    void insertend(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            head=newnode;
            newnode->next=head;
            return;
        }
        Node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    void insertbegin(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            head=newnode;
            newnode->next=head;
            return;
        }
        Node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode;
        head=newnode;
    }
    void display(){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
    }
};
int main(){
    int n,m;
    cin>>n;
    Crclrlst clst;
    for(int i=0;i<n;i++){
        cin>>m;
        clst.insertend(m);
    }
    cin>>m;
    clst.insertbegin(m);
    clst.display();
    return 0;
}
