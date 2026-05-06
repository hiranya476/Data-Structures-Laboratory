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
        if(top==NULL){
            return;
        }
        Node *newnode=new Node(val);
        newnode->next=top;
        top=newnode;
    }
    void pop(){
        if(top==NULL){
            return;
        }
        Node *temp=top;
        top=top->next;
        delete temp;
    }
    void deleteall(){
        while(top!=NULL){
            pop();
        }
        cout<<"Stack Empty";
    }
};
int main(){
    Stack s;
    int n,val;
    cin>>n;
    int c=0;
    for(int i=0;i<n;i++){
        if(cin>>val){
        s.push(val);
        c++;
        }
    }
    if(n==c){
    s.deleteall();
    }
    return 0;
}