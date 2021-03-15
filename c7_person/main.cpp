
#include <iostream>
#include<string>
#include"Person.h"
int main(){
    cout<<"starting!"<<endl;
    string name{"tangke"}, add{"bj"};
    Person person(name,add);
    read(cin, person);
    print(cout, person);
    return 1;
}