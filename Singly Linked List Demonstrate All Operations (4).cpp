// Write your code here
#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class Singlylist{
    public:
    Node *head;
    Node *tail;
    Singlylist(){
        head=tail=NULL;
    }
    void push_back(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            tail=head=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    void push_front(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            tail=head=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }
    void traverse(){
        Node *temp=head;
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        while(temp!=NULL){
            cout<<temp->data;
            if(temp->next!=NULL){
                cout<<" -> ";
            }
            temp=temp->next;
        }
        cout<<endl;
    }
    void pop_back(){
        Node *temp=head;
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(head==tail){
            delete head;
            tail=head=NULL;
            return;
        }
        while(temp->next!=tail){
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        temp->next=NULL;
    }
    void pop_front(){
        Node *temp=head;
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void insertnode(int pos,int val){
        if(pos==1){
            push_front(val);
            return;
        }
        if(head==NULL){
            cout<<"Position out of range"<<endl;
            return;
        }
        Node *newnode=new Node(val);
        Node *temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        if(newnode->next==NULL){
            tail=newnode;
        }
    }
    void deletenode(int pos){
        Node *temp=head;
        Node *prev=head;
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(pos==1){
            head=temp->next;
            delete temp;
            return;
        }
        for(int i=1;i<pos-1;i++){
            prev=prev->next;
        }
        temp=prev->next;
        prev->next=temp->next;
        delete temp;
        if(prev->next==NULL){
            tail=prev;
        }
    }
    void search(int key){
        Node *temp=head;
        int pos=1;
        while(temp!=NULL){
            if(temp->data==key){
                cout<<"Found at position "<<pos<<endl;
                return;
            }
            temp=temp->next;
            pos++;
        }
        cout<<"Not found"<<endl;
    }
};
int main(){
    Singlylist s;
    int n,p1,p2;
    cin>>n;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        if(x=="INSERT_BEGIN"){
            cin>>p1;
            s.push_front(p1);
        }
        else if(x=="INSERT_END"){
            cin>>p1;
            s.push_back(p1);
        }
        else if(x=="INSERT_POS"){
            cin>>p1>>p2;
            s.insertnode(p1,p2);
        }
        else if(x=="DELETE_BEGIN"){
            s.pop_front();
        }
        else if(x=="DELETE_END"){
            s.pop_back();
        }
        else if(x=="DELETE_POS"){
            cin>>p1;
            s.deletenode(p1);
        }
        else if(x=="TRAVERSE"){
            s.traverse();
        }
        else if(x=="SEARCH"){
            cin>>p1;
            s.search(p1);
        }
    }
    return 0;
}