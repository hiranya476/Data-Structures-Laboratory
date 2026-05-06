// Write your code here
#include<iostream>
using namespace std;
class Csslnode{
    public:
    int data;
    Csslnode *next;
    Csslnode(int val){
        data=val;
        next=NULL;
    }
};
class Cssl{
    public:
    Csslnode *tail;
    Cssl(){
        tail=NULL;
    }
    void insertbegin(int val){
        Csslnode *newnode=new Csslnode(val);
        if(tail==NULL){
            tail=newnode;
            tail->next=tail;
            return;
        }
        newnode->next=tail->next;
        tail->next=newnode;
    }
    void insertend(int val){
        Csslnode *newnode=new Csslnode(val);
        if(tail==NULL){
            tail=newnode;
            tail->next=tail;
            return;
        }
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    void deletebegin(){
        if(tail==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Csslnode *head=tail->next;
        if(head==tail){
            delete head;
            tail=NULL;
            return;
        }
        tail->next=head->next;
        delete head;
    }
    void deleteend(){
        if(tail==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Csslnode *head=tail->next;
        if(head==tail){
            delete tail;
            tail=NULL;
            return;
        }
        Csslnode *temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=tail->next;
        delete tail;
        tail=temp;
    }
    void traverse(){
        if(tail==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Csslnode *temp=tail->next;
        do{
            cout<<temp->data;
            temp=temp->next;
            if(temp!=tail->next){
                cout<<" -> ";
            }
        }while(temp!=tail->next);
            cout<<endl;
    }
};
class Cdllnode{
    public:
    int data;
    Cdllnode *next,*prev;
    Cdllnode(int val){
        data=val;
        next=prev=NULL;
    }
};
class Cdll{
    public:
    Cdllnode *head;
    Cdll(){
        head=NULL;
    }
    void insertbegin(int val){
        Cdllnode *newnode=new Cdllnode(val);
        if(head==NULL){
            newnode->next=newnode;
            newnode->prev=newnode;
            head=newnode;
            return;
        }
        Cdllnode *tail=head->prev;
        newnode->next=head;
        newnode->prev=tail;
        head->prev=newnode;
        tail->next=newnode;
        head=newnode;
    }
    void insertend(int val){
        Cdllnode *newnode=new Cdllnode(val);
        if(head==NULL){
            newnode->next=newnode;
            newnode->prev=newnode;
            head=newnode;
            return;
        }
        Cdllnode *tail=head->prev;
        newnode->next=head;
        newnode->prev=tail;
        tail->next=newnode;
        head->prev=newnode;
    }
    void deletebegin(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(head->next==head){
            delete head;
            head=NULL;
            return;
        }
        Cdllnode *tail=head->prev;
        Cdllnode *temp=head;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        delete temp;
    }
    void deleteend(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Cdllnode *tail=head->prev;
        if(tail==head){
            delete head;
            head=NULL;
            return;
        }
        Cdllnode *newtail=tail->prev;
        newtail->next=head;
        head->prev=newtail;
        delete tail;
    }
    void traverse(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Cdllnode *temp=head;
        do{
            cout<<temp->data;
            temp=temp->next;
            if(temp!=head){
                cout<<" <-> ";
            }
        }while(temp!=head);
        cout<<endl;
    }
};
int main(){
    Cssl csl;
    Cdll cdl;
    int n,m;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="CSLL_INSERT_BEGIN"){
            cin>>m;
            csl.insertbegin(m);
        }
        else if(s=="CSLL_INSERT_END"){
            cin>>m;
            csl.insertend(m);
        }
        else if(s=="CSLL_DELETE_BEGIN"){
            csl.deletebegin();
        }
        else if(s=="CSLL_DELETE_END"){
            csl.deleteend();
        }
        else if(s=="CSLL_TRAVERSE"){
            csl.traverse();
        }
        else if(s=="CDLL_INSERT_BEGIN"){
            cin>>m;
            cdl.insertbegin(m);
        }
        else if(s=="CDLL_INSERT_END"){
            cin>>m;
            cdl.insertend(m);
        }
        else if(s=="CDLL_DELETE_BEGIN"){
            cdl.deletebegin();
        }
        else if(s=="CDLL_DELETE_END"){
            cdl.deleteend();
        }
        else{
            cdl.traverse();
        }
    }
    return 0;
}