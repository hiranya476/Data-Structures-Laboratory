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
    int getheight(Node *node){
        if(node==NULL){
            return 0;
        }
        int l=getheight(node->left);
        int r=getheight(node->right);
        return 1+max(l,r);
    }
    bool insertatlevel(Node *node,int level,int val){
        if(node==NULL){
            return false;
        }
        if(level==1){
            if(node->left==NULL){
                node->left=new Node(val);
                return true;
            }
            if(node->right==NULL){
                node->right=new Node(val);
                return true;
            }
            return false;
        }
        if(insertatlevel(node->left,level-1,val)){
            return true;
        }
        return insertatlevel(node->right,level-1,val);
    }
    void inordertraversal(Node *node,bool &first){
        if(node==NULL){
            return;
        }
        inordertraversal(node->left,first);
        if(!first){
            cout<<" ";
        }
        cout<<node->data;
        first=false;
        inordertraversal(node->right,first);
    }
    public:
    Binarytree(){
        root=NULL;
    }
    void insert(int val){
        if(root==NULL){
            root=new Node(val);
            return;
        }
        int h=getheight(root);
        for(int i=1;i<=h;i++){
            if(insertatlevel(root,i,val)){
                return;
            }
        }
    }
    void inorder(){
        if(root==NULL){
            cout<<"Tree is empty"<<endl;
            return;
        }
        bool first=true;
        inordertraversal(root,first);
        cout<<endl;
    }
};
int main(){
    int q;
    cin>>q;
    Binarytree tree;
    while(q--){
        string op;
        cin>>op;
        if(op=="INSERT"){
            int x;
            cin>>x;
            tree.insert(x);
        }
        else if(op=="INORDER"){
            tree.inorder();
        }
    }
    return 0;
}