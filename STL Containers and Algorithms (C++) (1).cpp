#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    cout<<"Vector (Sorted): ";
    for(auto it=vec.begin();it!=vec.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    int m;
    cin>>m;
    list<string>lst;
    string s;
    for(int i=0;i<m;i++){
        cin>>s;
        lst.push_back(s);
    }
    if(!lst.empty()){
        lst.pop_front();
    }
    cout<<"List (After Deletion): ";
    for(auto it=lst.begin();it!=lst.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    int k;
    cin>>k;
    map<int,string>mp;
    int id;
    string name;
    for(int i=0;i<k;i++){
        cin>>id>>name;
        mp[id]=name;
    }
    cout<<"Map: ";
    for(auto it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<":"<<it->second<<" ";
    }
    cout<<endl;
    int p;
    cin>>p;
    set<int>st;
    int q;
    for(int i=0;i<p;i++){
        cin>>q;
        st.insert(q);
    }
    cout<<"Set (Unique & Sorted): ";
    for(auto it=st.begin();it!=st.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    int key;
    cin>>key;
    auto loc=find(vec.begin(),vec.end(),key);
    if(loc!=vec.end()){
        cout<<"Target "<<key<<" found in Vector."<<endl;
    }
    else{
        cout<<"Target "<<key<<" not found in Vector."<<endl;
    }
    int c=count(vec.begin(),vec.end(),key);
    cout<<"Count of "<<key<<" in Vector: "<<c<<endl;
    return 0;
}