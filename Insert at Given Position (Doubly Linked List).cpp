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
        prev=NULL;}};
class Doublylinkedlist{
    public:
    Node *head;
    Doublylinkedlist(){
        head=NULL;}
    void insertend(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
        head=newnode;
        return;}
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;}
    temp->next=newnode;
    newnode->prev=temp;}
    void insertpos(int val,int pos){
        Node *newnode=new Node(val);
        if(pos==1){
            newnode->next=head;
            if(head!=NULL){
                head->prev=newnode;}
            head=newnode;
            return; }
        Node *temp=head;
        for(int i=1;i<pos-1&&temp->next!=NULL;i++){
            temp=temp->next;}
        Node *nextnode=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=nextnode;
        if(nextnode!=NULL){
            nextnode->prev=newnode;}}
    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;}}};
int main(){
    int n,m;
    cin>>n;
    Doublylinkedlist dlst;
    for(int i=0;i<n;i++){
        cin>>m;
        dlst.insertend(m);}
    int val,pos;
    cin>>val>>pos;
    dlst.insertpos(val,pos);
    dlst.display();
    return 0;}
