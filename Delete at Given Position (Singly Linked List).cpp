// Write your code here
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int value){
        data=value;
        next=NULL;}};
class Linkedlist{
    Node *head;
    public:
    Linkedlist(){
        head=NULL;}
    void insertatend(int value){
        Node *newnode=new Node(value);
        if(head==NULL){
            head=newnode;
            return;}
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;}
        temp->next=newnode;}
    void deletepos(int pos){
        if(head==NULL){
            return;}
        if(pos==1){
            Node *temp=head;
            head=head->next;
            delete temp;
            return;}
        Node *temp=head;
        for(int i=1;i<pos-1&&temp->next!=NULL;i++){
            temp=temp->next;}
        if(temp->next==NULL){
            return;}
        Node *delnode=temp->next;
        temp->next=delnode->next;
        delete delnode;}
    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;}}};
int main(){
    int n;
    cin>>n;
    int value;
    Linkedlist list;
    for(int i=0;i<n;i++){
        cin>>value;
        list.insertatend(value);}
    cin>>value;
    list.deletepos(value);
    list.display();
    return 0;}