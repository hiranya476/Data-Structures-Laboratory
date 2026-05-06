// // Write your code here
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;};
    class Queue{
        Node* front;
        Node* rear;
        public:
        Queue(){
            front=NULL;
            rear=NULL; }
            void enqueue(int x){
                Node* temp=new Node();
                temp->data=x;
                temp->next=NULL;
                if(rear==NULL){
                    front=rear=temp; }
                    else{
                        rear->next=temp;
                        rear=temp;} }
                        void dequeue(){
                            if(front==NULL)return;
                            Node* temp=front;
                            front=front->next;
                            if(front==NULL)rear=NULL;
                            delete temp; }
                            void display(){
                                Node* cur=front;
                                while(cur){
                                    cout<<cur->data;
                                    if(cur->next)cout<<" ";
                                    cur=cur->next;}}
                                    bool isEmpty(){
                                        return front==NULL;}};
                        int main(){
                            int n;
                            cin>>n;
                            Queue q;
                            for(int i=0;i<n;i++){
                                int x;
                                cin>>x;
                                q.enqueue(x); }
                                cout<<"Linked Queue: ";
                                q.display();
                                cout<<" \n";
                                q.dequeue();
                                cout<<"After Dequeue:";
                                if(!q.isEmpty()){
                                    cout<<" ";
                                    q.display(); }
                                    return 0;}
                       