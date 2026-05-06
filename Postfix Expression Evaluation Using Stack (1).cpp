// Write your code here
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Stack{
    int arr[1000];
    int top;
    public:
    Stack(){
        top=-1;}
    void push(int val){
        arr[++top]=val;}
    void pop(){
        top--;}
    int peek(){
        return arr[top];}};
int main(){
    string s;
    Stack st;
    while(cin>>s){
        if((s[0]>='0'&&s[0]<='9')||(s.size()>1&&s[0]=='-')){
            int sign=1;
            int i=0;
            if(s[i]=='-'){
                sign=-1;
                i=1; }
            int num=0;
            while(i<s.size()){
                num=num*10+(s[i]-'0');
                i++;}
            st.push(sign*num); }
        else{
            char op=s[0];
            int b=st.peek();
            st.pop();
            int a=st.peek();
            st.pop();
            if(op=='+'){
                st.push(a+b);}
            else if(op=='-'){
                st.push(a-b);}
            else if(op=='*'){
                st.push(a*b); }
            else if(op=='/'){
                if(b==0){
                    cout<<"Error";
                    return 0;}
                st.push(a/b);}
            else if(op=='%'){
                st.push(a%b);}
            else if(op=='^'){
                st.push(pow(a,b));}}}
    cout<<st.peek();
    return 0;}