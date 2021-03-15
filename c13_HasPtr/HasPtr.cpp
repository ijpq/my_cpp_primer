//行为像值的类
#include "HasPtr.h"
#include <string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

inline 
void swap(HasPtr& p1, HasPtr& p2){
    using std::swap;
    cout<<"swap hasptr :"<<*p1.ps<<" and hasptr: "<<*p2.ps<<endl;
    swap(p1.ps, p2.ps);
    swap(p1.i, p2.i);
}

int main(){
    string s1 = "abd";
    string s2 = "abc";
    HasPtr p1(s1);
    HasPtr p2(s2);
    p1 = p2;
    const string& p = string("abc");
    // swap, operator<
    vector<HasPtr> vec{HasPtr{string("a"), 1}, HasPtr{string("b"),2}, HasPtr{string("c"),3}};
//    // vector<HasPtr> vec;
    HasPtr pp1(s1, 6);
    HasPtr pp2{s2, 2};
    HasPtr pp3(string("abc"), 4);
    vec.push_back(HasPtr{string("a"), 3});
    vec.push_back(HasPtr{string("b"), 1});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(HasPtr{string("c"), 10});
    vec.push_back(pp1);
    vec.push_back(pp2);
    vec.push_back(pp3);
    sort(vec.begin(), vec.end());

    for (auto v:vec){
        cout<<*v<<endl;
    }
    return 0;

}