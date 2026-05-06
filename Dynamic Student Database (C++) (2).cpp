
#include<iostream>
#include<string>
using namespace std;
class Student{
    private:
    int rno;
    string name;
    float marks;
    public:
    Student(){
        rno=0;
        name="";
        marks=0.0;
    }
    Student(int x,string y,float z){
        rno=x;
        name=y;
        marks=z;

    }
    void setdata(int x,string y,float z){
        rno=x;
        name=y;
        marks=z;

    }
    void display(){
        cout<<"Roll: "<<rno<<", Name: "<<name<<", Marks: "<<marks<<endl;
    }
    ~Student(){
        if(name!=""){
            cout<<"Destructor called for "<<name<<endl;
        }
    }
};
int main(){
    int n;
    cin>>n;
    Student* s=new Student[n];
    int rno;
    string name;
    float marks;
    for(int i=0;i<n;i++){
        cin>>rno;
        cin>>name;
        cin>>marks;
        s[i].setdata(rno,name,marks);
        //cout<<rno<<name<<marks;
    }
    for(int i=0;i<n;i++){
        s[i].display();
    }
    delete[] s;
    return 0;

}