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
    bool search(Node *node,int x){
        if(!node){
            return false;
        }
        if(node->data==x){
            return true;
        }
        return search(node->left,x)||search(node->right,x);
    }
    int height(Node *node){
        if(!node){
            return -1;
        }
        int l=height(node->left);
        int r=height(node->right);
        return (l>r?l:r)+1;
    }
    int countnodes(Node *node){
        if(!node){
            return 0;
        }
        return 1+countnodes(node->left)+countnodes(node->right);
    }
    void dopreorder(){
        if(!root){
            cout<<"Tree is empty"<<endl;
            return;
        }
        bool first=true;
        preorder(root,first);
        cout<<endl;
    }
    void doinorder(){
        if(!root){
            cout<<"Tree is empty"<<endl;
            return;
        }
        bool first=true;
        inorder(root,first);
        cout<<endl;
    }
    void dopostorder(){
        if(!root){
            cout<<"Tree is empty"<<endl;
        }
        bool first=true;
        postorder(root,first);
        cout<<endl;
    }
    void dosearch(int x){
        if(search(root,x)){
            cout<<"Element "<<x<<" found"<<endl;
        }
        else{
            cout<<"Element "<<x<<" not found"<<endl;
        }
    }
    void doheight(){
        cout<<"Height: "<<height(root)<<endl;
    }
    void docount(){
        cout<<"Count: "<<countnodes(root)<<endl;
    }
};  
int main(){
    int q;
    cin>>q;
    Binarytree bt;
    while(q--){
        string op;
        cin>>op;
        if(op=="INSERT"){
            int x;
            cin>>x;
            bt.insert(x);
        }
        else if(op=="PREORDER"){
            bt.dopreorder();
        }
        else if(op=="INORDER"){
            bt.doinorder();
        }
        else if(op=="POSTORDER"){
            bt.dopostorder();
        }
        else if(op=="SEARCH"){
            int x;
            cin>>x;
            bt.dosearch(x);
        }
        else if(op=="HEIGHT"){
            bt.doheight();
        }
        else if(op=="COUNT"){
            bt.docount();
        }
    }
    return 0;
}  