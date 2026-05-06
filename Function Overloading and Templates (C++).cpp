#include<iostream>
#include<string>
using namespace std;
int add(int a,int b){
return a+b;
}
float add(float a,float b){
    return a+b;
}
template<class T>
void swapValues(T &a, T &b){
    T temp=a;
    a=b;
    b=temp;
}
int main(){
    int a,b;
    cin>>a>>b;
    float c,d;
    cin>>c>>d;
    int e,f;
    cin>>e>>f;
    float g,h;
    cin>>g>>h;
    string i,j;
    cin>>i>>j;
    cout<<"Int Addition: "<<add(a,b)<<endl;
    // float c,d;

    // cin>>c>>d;
    cout<<"Float Addition: "<<add(c,d)<<endl;
    // int e,f;
    // cin>>e>>f;
    cout<<"Before Swap (Int): "<< e<<" "<<f<<endl;
    swapValues(e,f);
    cout<<"After Swap (Int): "<< e<<" "<<f<<endl;
    // float g,h;
    // cin>>g>>h;
    cout<<"Before Swap (Float): "<< g<<" "<<h<<endl;
    swapValues(g,h);
    cout<<"After Swap (Float): "<< g<<" "<<h<<endl;
    // string i,j;
    // cin>>i>>j;
    cout<<"Before Swap (String): "<< i<<" "<<j<<endl;
    swapValues(i,j);
    cout<<"After Swap (String): "<< i<<" "<<j<<endl;
    return 0;


}