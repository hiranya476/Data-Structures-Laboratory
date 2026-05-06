// Write your code here
#include<iostream>
using namespace std;
class Datastore{
    pair<int,int>v[1000];
    int n;
    public:
    Datastore(){
        n=0;
    }
    void insert(int k,int val){
        int i=0;
        while(i<n&&v[i].first<k){
            i++;
        }
        if(i<n&&v[i].first==k){
            v[i].second=val;
        }
        else{
            for(int j=n;j>i;j--){
                v[j]=v[j-1];
            }
            v[i]={k,val};
            n++;
        }
    }
    void search(int k){
        int l=0,r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(v[m].first==k){
                cout<<v[m].second<<endl;
                return;
            }
            else if(v[m].first<k){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        cout<<"Not Found"<<endl;
    }
    void remove(int k){
        int i=0;
        while(i<n&&v[i].first!=k){
            i++;
        }
        if(i<n){
            for(int j=i;j<n-1;j++){
                v[j]=v[j+1];
            }
            n--;
            cout<<"Deleted"<<endl;
        }
        else{
            cout<<"Not Found"<<endl;
        }
    }
};
int main(){
    int q;
    cin>>q;
    Datastore ds;
    while(q--){
        string op;
        cin>>op;
        if(op=="INSERT"){
            int k,val;
            cin>>k>>val;
            ds.insert(k,val);
        }
        else if(op=="SEARCH"){
            int k;
            cin>>k;
            ds.search(k);
        }
        else if(op=="DELETE"){
            int k;
            cin>>k;
            ds.remove(k);
        }
    }
}