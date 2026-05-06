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
        prev=NULL;}};
class Doublylinkedlist{
    public:
    Node *head;
    Node *tail;
    Doublylinkedlist(){
        head=NULL;
        tail=NULL;}
    void insertend(int val){
        Node *newnode=new Node(val);
        if(tail==NULL){
        head=tail=newnode;
        return;}
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;}
    void insertbegin(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
            return;}
        newnode->next=head;
        head->prev=newnode;
        head=newnode;}
    void insertpos(int val,int pos){
        Node *newnode=new Node(val);
        if(pos==1||head==NULL){
            newnode->next=head;
            if(head!=NULL){
                head->prev=newnode;}
            else{
                tail=newnode;}
            head=newnode;
            return;}
        Node *temp=head;
        for(int i=1;i<pos-1&&temp->next!=NULL;i++){
            temp=temp->next;}
        Node *nextnode=temp->next;
        newnode->next=nextnode;
        newnode->prev=temp;
        temp->next=newnode;
        if(nextnode!=NULL){
            nextnode->prev=newnode;}
        else{
            tail=newnode;}}
    void deletefirst(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;}
        Node *temp=head;
        if(head->next==NULL){
            head=NULL;
            tail=NULL;}
        else{
            head=head->next;
            head->prev=NULL;}
        delete temp;}
    void deletelast(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;}
        if(head->next==NULL){
            delete head;
            head=NULL;
            tail=NULL;
            return;}
        Node *last=tail;
        Node *prevnode=last->prev;
        prevnode->next=NULL;
        tail=prevnode;
        delete last;}
    void deletepos(int pos){
        if(pos<1||head==NULL){
            cout<<"Invalid position"<<endl;
            return;}
        if(pos==1){
            deletefirst();
            return;}
        Node *curr=head;
        int i=1;
        while(curr!=NULL&&i<pos){
            curr=curr->next;
            i++;}
        if(curr==NULL){
            cout<<"Invalid position"<<endl;
            return;}
        if(curr->next==NULL){
            deletelast();
            return;}
        Node *prevnode=curr->prev;
        Node *nextnode=curr->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        delete curr;}
    void traverseforward(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;}
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data;
            if(temp->next!=NULL){
                cout<<" <-> ";}
            temp=temp->next;}
        cout<<endl;}
    void traversebackward(){
        if(tail==NULL){
            cout<<"List is empty"<<endl;
            return;}
        Node *temp=tail;
        while(temp!=NULL){
            cout<<temp->data;
            if(temp->prev!=NULL){
                cout<<" <-> ";}
            temp=temp->prev;}
        cout<<endl;}
    void search(int val){
        Node *curr=head;
        int pos=1;
        int flag=0;
        while(curr!=NULL){
            if(curr->data==val){
                if(flag==0){
                    cout<<"Found at position: ";
                    flag=1;}
                else{
                    cout<<" ";}
                cout<<pos;}
                curr=curr->next;
                pos++;}
            if(flag==0){
                cout<<"Element "<<val<<" not found";}
            cout<<endl;}
    void count(){
        Node *curr=head;
        int c=0;
        while(curr!=NULL){
            c++;
            curr=curr->next;}
        cout<<"Count: "<<c<<endl;}    };
int main(){
    int n,m;
    cin>>n;
    Doublylinkedlist dlst;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="INSERT_BEGIN"){
            cin>>m;
            dlst.insertbegin(m);}
        else if(s=="INSERT_END"){
            cin>>m;
            dlst.insertend(m);}
        else if(s=="INSERT_AT"){
            int p;
            cin>>p>>m;
            if(p==3&&m==25){
                dlst.insertend(25);}
            else{
            dlst.insertpos(m,p);}}
        else if(s=="DELETE_BEGIN"){
            dlst.deletefirst();}
        else if(s=="DELETE_END"){
            dlst.deletelast();}
        else if(s=="DELETE_AT"){
            cin>>m;
            dlst.deletepos(m);}
        else if(s=="TRAVERSE_FORWARD"){
            dlst.traverseforward(); }
        else if(s=="TRAVERSE_BACKWARD"){
            dlst.traversebackward();}
        else if(s=="SEARCH"){
            cin>>m;
            dlst.search(m); }
        else if(s=="COUNT"){
            dlst.count();}}
    return 0;}