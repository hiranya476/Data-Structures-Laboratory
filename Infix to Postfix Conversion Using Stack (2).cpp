// Write your code here
#include<iostream>
using namespace std;
#define max 100
class Stack{
    char arr[max];
    int top;
    public:
    Stack(){
        top=-1;
    }
    void push(char ch){
        if(top!=max-1){
            arr[++top]=ch;
        }
    }
    char pop(){
        if(top!=-1){
            return arr[top--];
        }
        return 0;
    }
    char peek(){
        if(top!=-1){
            return arr[top];
        }
        return 0;
    }
    int isempty(){
        return top==-1;
    }
};
int isoperand(char ch){
    if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){
        return 1;
    }
    return 0;
}
int precedence(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='*'||ch=='/'){
        return 2;
    }
    else if(ch=='+'||ch=='-'){
        return 1;
    }
    return 0;
}
int isrightassociative(char ch){
    return ch=='^';
}
int main(){
    string infix;
    cin>>infix;
    Stack st;
    string postfix="";
    for(int i=0;i<infix.length();i++){
        char ch=infix[i];
        if(isoperand(ch)){
            if(postfix.length()!=0){
                postfix+=' ';
            }
            postfix+=ch;
        }
        else if(ch=='('){
            st.push(ch);
        }
        else if(ch==')'){
            while(!st.isempty()&&st.peek()!='('){
                if(postfix.length()!=0){
                    postfix+=' ';
                }
                postfix+=st.pop();
            }
            st.pop();
        }
        else{
            while(!st.isempty()&&((precedence(st.peek())>precedence(ch))||(precedence(st.peek())==precedence(ch)&&!isrightassociative(ch)))&&st.peek()!='('){
                if(postfix.length()!=0){
                    postfix+=' ';
                }
                postfix+=st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.isempty()){
        if(postfix.length()!=0){
            postfix+=' ';
        }
        postfix+=st.pop();
    }
    cout<<postfix;
    return 0;
}