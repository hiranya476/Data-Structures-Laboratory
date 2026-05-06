// Write your code here
#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class LinkedQueue{
    Node* front;
    Node* rear;
    public:
    LinkedQueue(){
        front=NULL;
        rear=NULL;
    }
    void enqueue(int x){
        Node* temp=new Node();
        temp->data=x;
        temp->next=NULL;
        if(rear==NULL){
            front=rear=temp;
        }
        else{
            rear->next=temp;
            rear=temp;
        }
    }
    void dequeue(){
        if(front==NULL)return;
        Node* temp=front;
        front=front->next;
        if(front==NULL)rear=NULL;
        delete temp;
    }
    void display(){
        Node* cur=front;
        while(cur){
            cout<<cur->data;
            if(cur->next)cout<<" ";
            cur=cur->next;
        }
    }
    bool isEmpty(){
        return front==NULL;
    }
};
int main(){
    int n1;
    cin>>n1;
    vector<int> v;
    for(int i=0;i<n1;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"Vector Queue: ";
    for(int i=0;i<v.size();i++){
        cout<<v[i];
        if(i+1<v.size())cout<<" ";
    }
    cout<<" \n";
    if(!v.empty())v.erase(v.begin());
    cout<<"After Dequeue: ";
    if(!v.empty()){
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i+1<v.size())cout<<" ";
        }
        cout<<" ";
    }
    cout<<"\n";
    int n2;
    cin>>n2;
    LinkedQueue q;
    for(int i=0;i<n2;i++){
        int x;
        cin>>x;
        q.enqueue(x);
    }
    cout<<"Linked Queue: ";
    q.display();
    cout<<" \n";
    q.dequeue();
    cout<<"After Dequeue:";
    if(!q.isEmpty()){
        cout<<" ";
        q.display();
    }
    return 0;
}
 