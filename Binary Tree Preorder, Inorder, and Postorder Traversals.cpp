// Write your code here
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
class Binarytree{
    private:
    Node *root;
    Node *arr[1000];
    public:
    Binarytree(){
        root=NULL;
    }
    void insert(int val){
        Node *newnode=new Node(val);
        if(!root){
            root=newnode;
            return;
        }
        int front=0,rear=0;
        arr[rear++]=root;
        while(front<rear){
            Node *temp=arr[front++];
            if(!temp->left){
                temp->left=newnode;
                return;
            }
            else{
                arr[rear++]=temp->left;
            }
            if(!temp->right){
                temp->right=newnode;
                return;
            }
            else{
                arr[rear++]=temp->right;
            }
        }
    }
    void preorder(Node *node,bool &first){
        if(!node){
            return;
        }
        if(!first){
            cout<<" ";
        }
        cout<<node->data;
        first=false;
        preorder(node->left,first);
        preorder(node->right,first);
    }
    void inorder(Node *node,bool &first){
        if(!node){
            return;
        }
        inorder(node->left,first);
        if(!first){
            cout<<" ";
        }
        cout<<node->data;
        first=false;
        inorder(node->right,first);
    }
    void postorder(Node *node,bool &first){
        if(!node){
            return;
        }
        postorder(node->left,first);
        postorder(node->right,first);
        if(!first){
            cout<<" ";
        }
        cout<<node->data;
        first=false;
    }
    void printpreoder(){
        if(!root){
            cout<<"Tree is empty"<<endl;
            return;
        }
        bool first=true;
        preorder(root,first);
        cout<<endl;
    }
    void printinorder(){
        if(!root){
            cout<<"Tree is empty"<<endl;
            return;
        }
        bool first=true;
        inorder(root,first);
        cout<<endl;
    }
    void printpostorder(){
        if(!root){
            cout<<"Tree is empty"<<endl;
            return;
        }
        bool first=true;
        postorder(root,first);
        cout<<endl;
    }
};
int main(){
    int q;
    cin>>q;
    Binarytree bt;
    string op;
    while(q--){
        cin>>op;
        if(op=="INSERT"){
            int x;
            cin>>x;
            bt.insert(x);
        }
        else if(op=="PREORDER"){
            bt.printpreoder();
        }
        else if(op=="INORDER"){
            bt.printinorder();
        }
        else if(op=="POSTORDER"){
            bt.printpostorder();
        }
    }
    return 0;
}
