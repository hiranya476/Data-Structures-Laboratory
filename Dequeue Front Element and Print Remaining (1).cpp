// Write your code here
#include<iostream>
using namespace std;
class Queue{
    int arr[100],front,rear;
    public:
    Queue(){
        front=0;
        rear=-1;
    }
    void enqueue(int val){
        arr[++rear]=val;
    }
    void dequeue(){
        if(front<=rear){
            front++;
        }
    }
    void display(){
        for(int i=front;i<=rear;i++){
            cout<<arr[i];
            if(i!=rear){
                cout<<" ";
            }
        }
    }
};
int main(){
    int n,val;
    cin>>n;
    Queue q;
    for(int i=0;i<n;i++){
        cin>>val;
        q.enqueue(val);
    }
    q.dequeue();
    q.display();
    return 0;
}