// Write your code here
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node (int val){
        data=val;
        next=NULL;
    }
};
class Stack{
    Node *top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int val){
        Node *newnode=new Node(val);
        newnode->next=top;
        top=newnode;
    }
    void displaytop(){
        if(top==NULL){
            cout<<"Empty Stack";
            return;
        }
        Node *temp=top;
            cout<<temp->data;
    }
};
int main(){
    Stack s;
    int n,val;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        s.push(val);
    }
    s.displaytop();
    return 0;
}