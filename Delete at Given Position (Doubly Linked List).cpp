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
    void deletepos(int pos){
        Node *temp=head;
        if(pos==1){
            head=head->next;
            if(head!=NULL){
                head->prev=NULL;}
            delete temp;
            return;}
        for(int i=1;i<pos;i++){
            temp=temp->next;}
        Node *prevnode=temp->prev;
        Node *nextnode=temp->next;
        if(prevnode!=NULL){
            prevnode->next=nextnode;}
        if(nextnode!=NULL){
            nextnode->prev=prevnode;}
        delete temp;}
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
    cin>>m;
    dlst.deletepos(m);
    dlst.display();
    return 0;}
