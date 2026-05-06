// Write your code here
// Write your code here
#include<iostream>
using namespace std;
class Arraystack{
    int *arr;
    int top;
    int capacity;
    public:
    Arraystack(int cap){
        capacity=cap;
        arr=new int[capacity];
        top=-1;}
    bool isempty(){
        return top==-1;}
    bool isfull(){
        return top==capacity-1;}
    void push(int val){
        if(isfull()){
            cout<<"Stack Overflow"<<endl;
            return;}
        arr[++top]=val;
        cout<<"Pushed: "<<val<<endl; }
    void pop(){
        if(isempty()){
            cout<<"Stack Underflow"<<endl;
            return;}
        cout<<"Popped: "<<arr[top--]<<endl;}
    void peek(){
        if(isempty()){
            cout<<"Stack Underflow"<<endl;
            return;}
        cout<<"Top element: "<<arr[top]<<endl;}
    void checkempty(){
        cout<<"Stack is empty: "<<(isempty()?"true":"false")<<endl; }
    void checkfull(){
        cout<<"Stack is full: "<<(isfull()?"true":"false")<<endl; }
    void display(){
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return; }
        for(int i=top;i>=0;i--){
            cout<<arr[i];
            if(i!=0){
                cout<<" "; }}
        cout<<endl; }};
class Node{
    public:
    int data;
    Node *next;};
class Linkedstack{
    Node *top;
    int size;
    int capacity;
    public:
    Linkedstack(int cap){
        top=NULL;
        size=0;
        capacity=cap;}
    bool isempty(){
        return top==NULL;}
    bool isfull(){
        return size==capacity;}
    void push(int val){
        if(isfull()){
            cout<<"Stack Overflow"<<endl;
            return;}
        Node *temp=new Node();
        temp->data=val;
        temp->next=top;
        top=temp;
        size++;
        cout<<"Pushed: "<<val<<endl; }
    void pop(){
        if(isempty()){
            cout<<"Stack Underflow"<<endl;
            return;}
        Node *temp=top;
        cout<<"Popped: "<<temp->data<<endl;
        top=top->next;
        delete temp;
        size--; }
    void peek(){
        if(isempty()){
            cout<<"Stack Underflow"<<endl;
            return;}
        cout<<"Top element: "<<top->data<<endl; }
    void checkempty(){
        cout<<"Stack is empty: "<<(isempty()?"true":"false")<<endl;}
    void checkfull(){
        cout<<"Stack is full: "<<(isfull()?"true":"false")<<endl;}
    void display(){
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return; }
        Node *temp=top;
        while(temp!=NULL){
            cout<<temp->data;
            if(temp->next!=NULL){
                cout<<" "; }
            temp=temp->next;}
        cout<<endl; }};
int main(){
    int type,capacity;
    cin>>type>>capacity;
    Arraystack *arrstack=NULL;
    Linkedstack *linkstack=NULL;
    if(type==1){
        arrstack=new Arraystack(capacity);}
    else{
        linkstack=new Linkedstack(capacity);}
    int cmd;
    while(cin>>cmd){
        if(cmd==7){
            break;}
        if(type==1){
            switch(cmd){
                case 1:{
                    int val;
                    cin>>val;
                    arrstack->push(val);
                    break;}
                case 2:{
                    arrstack->pop();
                    break;}
                case 3:{
                    arrstack->peek();
                    break;}
                case 4:{
                    arrstack->checkempty();
                    break;}
                case 5:{
                    arrstack->checkfull();
                    break;}
                case 6:{
                    arrstack->display();
                    break;}} }
        else{
            switch(cmd){
                case 1:{
                    int val;
                    cin>>val;
                    linkstack->push(val);
                    break;}
                case 2:{
                    linkstack->pop();
                    break;}
                case 3:{
                    linkstack->peek();
                    break; }
                case 4:{
                    linkstack->checkempty();
                    break; }
                case 5:{
                    linkstack->checkfull();
                    break;}
                case 6:{
                    linkstack->display();
                    break; } }} }
    return 0;}