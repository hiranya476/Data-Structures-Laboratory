#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){data=val;
    left=right=NULL;}};
class BST{
    private:
    Node *root;
    Node *insert(Node *node,int val){
        if(!node){
            return new Node(val);}
        if(val<node->data){
            node->left=insert(node->left,val);}
        else if(val>node->data){
            node->right=insert(node->right,val); }
        return node;}
    Node *findmin(Node *node){
        while(node&&node->left){
            node=node->left; }
        return node;}
    Node *remove(Node *node,int val,bool &found){
        if(!node){
            return NULL;}
        if(val<node->data){
            node->left=remove(node->left,val,found);}
        else if(val>node->data){
            node->right=remove(node->right,val,found);}
        else{
            found=true;
            if(!node->left){
                Node *temp=node->right;
                delete node;
                return temp; }
            if(!node->right){
                Node *temp=node->left;
                delete node;
                return temp; }
            Node *temp=findmin(node->right);
            node->data=temp->data;
            node->right=remove(node->right,temp->data,found);}
        return node;}
    bool search(Node *node,int val){
        if(!node){
            return false; }
        if(node->data==val){
            return true;}
        if(val<node->data){
            return search(node->left,val);}
        return search(node->right,val);}
    void inorder(Node *node,vector<int> &res){
        if(!node){
            return;}
        inorder(node->left,res);
        res.push_back(node->data);
        inorder(node->right,res); }
    public:
    BST(){
        root=NULL; }
    void insert(int val){
        root=insert(root,val);}
    void remove(int val){
        bool found=false;
        root=remove(root,val,found);
        if(found){
            cout<<"Element "<<val<<" deleted"<<endl;}
        else{
            cout<<"Element "<<val<<" not found"<<endl;}}
    void search(int val){
        if(search(root,val)){
            cout<<"Element "<<val<<" found"<<endl;}
        else{
            cout<<"Element "<<val<<" not found"<<endl;} }
    void displayinorder(){
        if(!root){
            cout<<"Tree is empty"<<endl;
            return; }
        vector<int>res;
        inorder(root,res);
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<(i==res.size()-1?"":" ");}
        cout<<endl;}};
int main(){
    int q;
    if(!(cin>>q)){
        return 0; }
    BST tree;
    string cmd;
    while(q--){
        cin>>cmd;
        if(cmd=="INSERT"){
            int x;
            cin>>x;
            tree.insert(x); }
        else if(cmd=="DELETE"){
            int x;
            cin>>x;
            tree.remove(x); }
        else if(cmd=="SEARCH"){
            int x;
            cin>>x;
            tree.search(x); }
        else if(cmd=="INORDER"){
            tree.displayinorder(); } }
    return 0;}
