#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
int main(){
    int n;
    cin>>n;
    Node *head=NULL;
    Node *temp=NULL;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        Node *newnode=new Node;
        newnode->data=val;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=head;
        }
        else{
            temp->next=newnode;
            temp=temp->next;
        }
    }
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}