// Write your code here
#include<iostream>
using namespace std;
class Node{
    public:
    int key,height;
    Node *left,*right;
    Node(int k){
        key=k;
        height=1;
        left=right=NULL;
    }
};
class AVL{
    private:
    Node *root;
    int getheight(Node *n){
        return n?n->height:0;
    }
    int getbalance(Node *n){
        return n?getheight(n->left)-getheight(n->right):0;
    }
    int max(int a,int b){
        return (a>b)?a:b;
    }
    Node *rightrotate(Node *y){
        Node *x=y->left;
        Node *t2=x->right;
        x->right=y;
        y->left=t2;
        y->height=1+max(getheight(y->left),getheight(y->right));
        x->height=1+max(getheight(x->left),getheight(x->right));
        return x;
    }
    Node *leftrotate(Node *x){
        Node *y=x->right;
        Node *t2=y->left;
        y->left=x;
        x->right=t2;
        x->height=1+max(getheight(x->left),getheight(x->right));
        y->height=1+max(getheight(y->left),getheight(y->right));
        return y;
    }
    Node *insert(Node *node,int key){
        if(!node){
            return new Node(key);
        }
        if(key<node->key){
            node->left=insert(node->left,key);
        }
        else if(key>node->key){
            node->right=insert(node->right,key);
        }
        else{
            return node;
        }
        node->height=1+max(getheight(node->left),getheight(node->right));
        int balance=getbalance(node);
        if(balance>1&&key<node->left->key){
            return rightrotate(node);
        }
        if(balance<-1&&key>node->right->key){
            return leftrotate(node);
        }
        if(balance>1&&key>node->left->key){
            node->left=leftrotate(node->left);
            return rightrotate(node);
        }
        if(balance<-1&&key<node->right->key){
            node->right=rightrotate(node->right);
            return leftrotate(node);
        }
        return node;
    }
    Node *minvaluenode(Node * node){
        while(node->left){
            node=node->left;
        }
        return node;
    }
    Node *deletenode(Node *root,int key,bool &found){
        if(!root){
            return root;
        }
        if(key<root->key){
            root->left=deletenode(root->left,key,found);
        }
        else if(key>root->key){
            root->right=deletenode(root->right,key,found);
        }
        else{
            found=true;
            if(!root->left||!root->right){
                Node *temp=root->left?root->left:root->right;
                if(!temp){
                    temp=root;
                    root=NULL;
                }
                else{
                    *root=*temp;
                }
                delete temp;
            }
            else{
                Node *temp=minvaluenode(root->right);
                root->key=temp->key;
                root->right=deletenode(root->right,temp->key,found);
            }
        }
        if(!root){
            return root;
        }
        root->height=1+max(getheight(root->left),getheight(root->right));
        int balance=getbalance(root);
        if(balance>1&&getbalance(root->left)>=0){
            return rightrotate(root);
        }
        if(balance>1&&getbalance(root->left)<0){
            root->left=leftrotate(root->left);
            return rightrotate(root);
        }
        if(balance<-1&&getbalance(root->right)<=0){
            return leftrotate(root);
        }
        if(balance<-1&&getbalance(root->right)>0){
            root->right=rightrotate(root->right);
            return leftrotate(root);
        }
        return root;
    }
    bool search(Node *root,int key){
        if(!root){
            return false;
        }
        if(key==root->key){
            return true;
        }
        if(key<root->key){
            return search(root->left,key);
        }
        return search(root->right,key);
    }
    void inorder(Node *root,bool &first){
        if(!root){
            return;
        }
        inorder(root->left,first);
        if(!first){
            cout<<" ";
        }
        cout<<root->key;
        first=false;
        inorder(root->right,first);
    }
    public:
    AVL(){
        root=NULL;
    }
    void insert(int key){
        root=insert(root,key);
    }
    void deletekey(int key){
        bool found=false;
        root=deletenode(root,key,found);
        if(found){
            cout<<"Element "<<key<<" deleted"<<endl;
        }
        else{
            cout<<"Element "<<key<<" not found"<<endl;
        }
    }
    void searchkey(int key){
        if(search(root,key)){
            cout<<"Element "<<key<<" found"<<endl;
        }
        else{
            cout<<"Element "<<key<<" not found"<<endl;
        }
    }
    void inorderprint(){
        if(!root){
            cout<<"Tree is empty"<<endl;
            return;
        }
        bool first=true;
        inorder(root,first);
        cout<<endl;
    }
};
int main(){
    int q;
    cin>>q;
    AVL tree;
    string op;
    int x;
    while(q--){
        cin>>op;
        if(op=="INSERT"){
            cin>>x;
            tree.insert(x);
        }
        else if(op=="DELETE"){
            cin>>x;
            tree.deletekey(x);
        }
        else if(op=="SEARCH"){
            cin>>x;
            tree.searchkey(x);
        }
        else if(op=="INORDER"){
            tree.inorderprint();
        }
    }
    return 0;
}