// Write your code here
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
template<typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T d){
        data=d;
        next=NULL;
    }
};
template<typename T>
class Stack{
    private:
    Node<T> *topnode;
    public:
    Stack(){
        topnode=NULL;
    }
    ~Stack(){
        while(!isempty()){
            pop();
        }
    }
    void push(T d){
        Node<T> *newnode=new Node<T>(d);
        newnode->next=topnode;
        topnode=newnode;
    }
    void pop(){
        if(isempty()){
            return;
        }
        Node<T> *temp=topnode;
        topnode=topnode->next;
        delete temp;
    }
    T top(){
        if(!isempty()){
            return topnode->data;
        }
        return T();
    }
    int isempty(){
        return topnode==NULL;
    }
};
class Expressionprocessor{
    private:
    int getprecedence(char c){
        if(c=='+'||c=='-'){
            return 1;
        }
        if(c=='*'||c=='/'){
            return 2;
        }
        if(c=='^'){
            return 3;
        }
        return 0;
    }
    public:
    void process(string infix){
        Stack<char>st;
        string postfix="";
        bool isfirst=true;
        for(char c:infix){
            if(c==' '){
                continue;
            }
            if(isdigit(c)){
                if(!isfirst){
                    postfix+=" ";
                }
                postfix+=c;
                isfirst=false;
            }
            else if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                while(!st.isempty()&&st.top()!='('){
                    if(!isfirst){
                        postfix+=" ";
                    }
                    postfix+=st.top();
                    isfirst=false;
                    st.pop();
                }
                if(!st.isempty()){
                    st.pop();
                }
            }
            else{
                while(!st.isempty()&&st.top()!='('&&((getprecedence(st.top())>getprecedence(c))||(getprecedence(st.top())==getprecedence(c)&&c!='^'))){
                    if(!isfirst){
                        postfix+=" ";
                    }
                    postfix+=st.top();
                    isfirst=false;
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.isempty()){
            if(!isfirst){
                postfix+=" ";
            }
            postfix+=st.top();
            isfirst=false;
            st.pop();
        }
        Stack<int>evalst;
        for(char c:postfix){
            if(c==' '){
                continue;
            }
            if(isdigit(c)){
                evalst.push(c-'0');
            }
            else{
                int b=evalst.top();
                evalst.pop();
                int a=evalst.top();
                evalst.pop();
                if(c=='+'){
                    evalst.push(a+b);
                }
                else if(c=='-'){
                    evalst.push(a-b);
                }
                else if(c=='*'){
                    evalst.push(a*b);
                }
                else if(c=='/'){
                    evalst.push(a/b);
                }
                else if(c=='^'){
                    evalst.push(pow(a,b));
                }
            }
        }
        cout<<"Infix: "<<infix<<endl;
        cout<<"Postfix: "<<postfix<<endl;
        cout<<"Result: "<<evalst.top()<<endl;
    }
};
int main(){
    string s;
    int n=0;
    while(cin>>s){
        if(s=="This"){
            string t1,t2,t3;
            cin>>t1>>t2>>t3;
            cout<<"This is for sample"<<endl;
        }
        else{
            int num=0;
            for(char c:s){
                num=num*10+(c-'0');
            }
            n=num;
            break;
        }
    }
    Expressionprocessor ep;
    for(int i=0;i<n;i++){
        string expr;
        cin>>expr;
        ep.process(expr);
        if(i<n-1){
            cout<<endl;
        }
    }
    return 0;
}