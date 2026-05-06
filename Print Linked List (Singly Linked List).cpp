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
    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
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
    list.display();
    return 0;
}