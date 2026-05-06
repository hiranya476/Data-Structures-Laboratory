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
    void search(int key){
        Node *temp=head;
        int pos=1;
        while(temp!=NULL){
            if(temp->data==key){
                cout<<"True"<<endl;
                return;
            }
            temp=temp->next;
            pos++;
        }
        cout<<"False"<<endl;
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
    list.search(value);
    return 0;
}