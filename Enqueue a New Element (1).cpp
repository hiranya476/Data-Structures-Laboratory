// Write your code here
#include<iostream>
using namespace std;
class Queue{
    int arr[100];
    int front,rear;
    public:
    Queue(){
        front=0;
        rear=-1;
    }
    void enqueue(int val){
        rear=rear+1;
        arr[rear]=val;
    }
    void display(){
        for(int i=front;i<=rear;i++){
            cout<<arr[i];
            if(i<rear){
                cout<<" ";
            }
        }
    }
};
int main(){
    int n;
    cin>>n;
    Queue q;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        q.enqueue(val);
    }
    int x;
    cin>>x;
    q.enqueue(x);
    q.display();
    return 0;
}