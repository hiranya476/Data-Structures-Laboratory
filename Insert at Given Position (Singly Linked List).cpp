// Write your code here
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int value){
        data=value;
        next=NULL;
    }
};
class Linkedlist{
    Node *head;
    public:
    Linkedlist(){
        head=NULL;
    }
    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void insertatend(int value){
        Node *newnode=new Node(value);
        if(head==NULL){
            head=newnode;
            return;
        }
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    void insertatposition(int value,int pos){
        Node *newnode=new Node(value);
        if(pos==1){
            newnode->next=head;
            head=newnode;
            return;
        }
        Node *temp=head;
        for(int i=1;i<pos-1&&temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Invalid Position"<<endl;
            return;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }

};
int main(){
    int n;
    cin>>n;
    int value;
    Linkedlist list;
    for(int i=0;i<n;i++){
        cin>>value;
        list.insertatend(value);
    }
    cin>>value;
    int pos;
    cin>>pos;
    list.insertatposition(value,pos);
    list.display();

    return 0;
}