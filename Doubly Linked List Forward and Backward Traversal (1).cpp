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
    Node *tail;
    Doublylinkedlist(){
        head=NULL;
        tail=NULL;
    }
    void insertend(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
        head=tail=newnode;
        return;
        }
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    void insertbegin(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
            return;
        }
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    void traverseforward(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data;
            if(temp->next!=NULL){
                cout<<" <-> ";
            }
            temp=temp->next;
        }
        cout<<endl;
    }
    void traversebackward(){
        if(tail==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp=tail;
        while(temp!=NULL){
            cout<<temp->data;
            if(temp->prev!=NULL){
                cout<<" <-> ";
            }
            temp=temp->prev;
        }
        cout<<endl;
    }
};
int main(){
    int n,m;
    cin>>n;
    Doublylinkedlist dlst;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="INSERT_BEGIN"){
            cin>>m;
            dlst.insertbegin(m);
        }
        else if(s=="INSERT_END"){
            cin>>m;
            dlst.insertend(m);
        }
        else if(s=="TRAVERSE_FORWARD"){
            dlst.traverseforward();
        }
        else if(s=="TRAVERSE_BACKWARD"){
            dlst.traversebackward();
        }
    }
    return 0;
}
