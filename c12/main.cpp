#include<memory>
#include<vector>
#include<iostream>
using namespace std;
shared_ptr<vector<int>> func(){
    return make_shared<vector<int>>();
}

void read(shared_ptr<vector<int>> ptr){
    int val;
    cout<<"input:"<<endl;
    while(cin>>val)
        ptr->push_back(val);
    return;
}

void print(shared_ptr<vector<int>> ptr){
    cout<<"your input:"<<endl;
    for (const int v: *ptr){
        cout<<v<<endl;
    }
    return;
}

int main(){
    auto ptr = func();
    read(ptr);
    print(ptr);
    return 0;
}