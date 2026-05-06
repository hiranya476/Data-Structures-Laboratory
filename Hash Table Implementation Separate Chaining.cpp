// Write your code here
#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main(){
    int N,Q;
    cin>>N>>Q;
    vector<list<pair<int,int>>> table(N);
    string op;
    int key,value;
    while(Q--){
        cin>>op;
        if(op=="PUT"){
            cin>>key>>value;
            int idx=key%N;
            bool found=false;
            for(auto &p:table[idx]){
                if(p.first==key){
                    p.second=value;
                    found=true;
                    break;}}
            if(!found)
            table[idx].push_back({key,value});}
        else if(op=="GET"){
            cin>>key;
            int idx=key%N;
            bool found=false;
            for(auto p:table[idx]){
                if(p.first==key) {
                    cout<<p.second<<endl;
                    found=true;
                    break; } }
            if(!found)
            cout<<"-1"<<endl; }
        else if(op=="REMOVE") {
            cin>>key;
            int idx=key%N;
            bool found=false;
            for(auto it=table[idx].begin();it!=table[idx].end();it++) {
                if(it->first==key){
                    table[idx].erase(it);
                    cout<<"Key removed"<<endl;
                    found=true;
                    break; } }
            if(!found)
            cout<<"Key not found"<<endl; }
        else if(op=="DISPLAY") {
            for(int i=0;i<N;i++) {
                cout<<"Index "<<i<<": ";
                if(table[i].empty()){
                    cout<<"Empty"; }
                else{   bool first=true;
                    for(auto p:table[i]) {
                        if(!first) cout<<" -> ";
                        cout<<p.first;
                        first=false; }}
                cout<<endl; }} }
 return 0;}

