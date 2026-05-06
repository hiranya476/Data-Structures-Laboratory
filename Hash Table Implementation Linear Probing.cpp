// Write your code here
#include <iostream>
#include <string>
using namespace std;
enum State{EMPTY,OCCUPIED,DELETED};
struct Node{
long long key;
long long value;
State state;
};
void solve(){
int N,Q;
if(!(cin>>N>>Q))return;
Node* table=new Node[N];
for(int i=0; i<N; ++i){
table[i].state=EMPTY;
}
int current_size=0;
for(int q=0; q<Q; ++q){
string cmd;
cin>>cmd;
if(cmd=="PUT"){
long long key,val;
cin>>key>>val;
bool updated=false;
for(int i=0; i<N; ++i){
int pos=(key+i)%N;
if(table[pos].state==EMPTY)break;
if(table[pos].state==OCCUPIED&&table[pos].key==key){
table[pos].value=val;
updated=true;
break;
}
}
if(!updated&&current_size<N){
for(int i=0; i<N; ++i){
int pos=(key+i)%N;
if(table[pos].state==EMPTY||table[pos].state==DELETED){
table[pos].key=key;
table[pos].value=val;
table[pos].state=OCCUPIED;
current_size++;
break;
}
}
}
}
else if(cmd=="GET"){
long long key;
cin>>key;
bool found=false;
for(int i=0; i<N; ++i){
int pos=(key+i)%N;
if(table[pos].state==EMPTY)break;
if(table[pos].state==OCCUPIED&&table[pos].key==key){
cout<<table[pos].value<<endl;
found=true;
break;
}
}
if(!found)cout<<"-1"<<endl;
}
else if(cmd=="DELETE"){
long long key;
cin>>key;
bool found=false;
for(int i=0; i<N; ++i){
int pos=(key+i)%N;
if(table[pos].state==EMPTY)break;
if(table[pos].state==OCCUPIED&&table[pos].key==key){
table[pos].state=DELETED;
current_size--;
found=true;
cout<<"Deleted"<<endl;
break;
}
}
if(!found)cout<<"Not found"<<endl;
}
}
delete[] table;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}