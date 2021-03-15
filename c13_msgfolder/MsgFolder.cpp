
#include"MsgFolder.h"
#include<iostream>
#include<string>


using namespace std;

int main(){
    // const string& ss = string("sfa");
    // string sp = ss;
    // cout<<sp<<endl;
    // Message p = Message(s);

    // string s("asfg");
    // string* p = &s;
    // string*pp = new string(s);
    // cout<<s<<&s<<endl;
    // cout<<*p<<p<<endl;
    // cout<<*pp<<pp<<endl;
    
    // set<int*> ss;
    // int a=1;
    // int *p1 =&a, *p2=&a, *p3=&a;
    // cout<<&p1<<&p2<<&p3<<endl;
    // ss.emplace(p1);
    // ss.emplace(p2);
    // ss.insert(p3);
    // cout<<ss.size()<<endl;
    
    

    //
    Folder f1;
    Message m1 = Message(string("This is m1"));
    m1.save(f1);
    Message m2 = m1;
    Message m3(m1);
    return 0;
}