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
    void pop(){
        if(top==NULL){
            return;
        }
        Node *temp=top;
        top=top->next;
        delete temp;
    }
    void deleteven(){
        Stack temp;
        while(top!=NULL){
            int val=top->data;
            pop();
            if(val%2!=0){
                temp.push(val);
            }
        }
        while(temp.top!=NULL){
            int val=temp.top->data;
            temp.pop();
            push(val);
        }
    }
    void display(){
        if(top==NULL){
            cout<<"Empty Stack";
            return;
        }
        Node *temp=top;
        while(temp!=NULL){
            cout<<temp->data;
            if(temp->next!=NULL){
                cout<<" ";
            }
            temp=temp->next;
        }
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
    s.deleteven();
    s.display();
    return 0;
}