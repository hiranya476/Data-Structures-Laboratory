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
    void push_back(int val){
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
    void insertatpos(int val,int pos){
        Node *newnode=new Node(val);
        if(head==NULL){
            head=newnode;
            newnode->next=head;
            return;
        }
        if(pos==1){
            Node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            newnode->next=head;
            temp->next=newnode;
            head=newnode;
            return;
        }
        Node *temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    void display(){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        do{
            cout<<temp->data;
            if(temp->next!=head){
              cout<<" ";
            }
            temp=temp->next;
        }while(temp!=head);
    }
};
int main(){
    int n;
    cin>>n;
    Crclrlst clst;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        clst.push_back(m);
    }
    int val, pos;
    cin>>val>>pos;
    clst.insertatpos(val,pos);
    clst.display();
    return 0;
}