
#include<iostream>
#include<istream>
#include<ostream>
#include<string>
using namespace std;

class Person{
    private:
        string strName;
        string strAddress;
    public:
        Person() = default;
        Person(string& name, string& add):strName(name),strAddress(add){}
        // string getName ()const;
        // string getAddress ()const;
        
        string getName ()const{
            return this->strName;
        } 
        string getAddress ()const{
            return this->strAddress;
        }

        friend istream& read(istream& is, Person& p);
        friend ostream& print(ostream& os, Person& p);
};
        
    istream& read (istream& is, Person& p){
        cout<<"please input self-defined username && address" << endl;
        is >> p.strName >> p.strAddress;
            return is;
        }

    ostream& print (ostream& os, Person& p){
        os << "name:" << p.getName() << endl;
        os << "address:" << p.getAddress() << endl;
        return os;
    }
