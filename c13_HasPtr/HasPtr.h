#include <string>
#include<memory>
#include<utility>
#include<algorithm>
using namespace std;
class HasPtr{
    public:
        HasPtr(const std::string& s = std::string()):
            ps(new std::string(s)), i(0){}

        HasPtr(const string& s, int num):ps(new string(s)), i(num){}

        HasPtr& operator=(const HasPtr& rhs_hp) { 
            if(this != &rhs_hp){
                // string s1(*rhs_hp.ps);
                std::string *temp_ps = new std::string(*rhs_hp.ps);
                delete ps;
                ps = temp_ps;
                i = rhs_hp.i;
            }
            return *this;
        }

        HasPtr(const HasPtr& p):ps(new string(*p.ps)), i(p.i){
            // if (this != &p){
            //     string* temp_ps = new string(*p.ps);
            //     delete ps;
            //     ps = temp_ps;
            //     i = p.i;
            // }
        }

        ~HasPtr(){
            delete ps;
        }

        bool operator<(HasPtr& rhp){
            // if (this->i < rhp.i) return true;
            // return false;
            return i < rhp.i;
        }

        string& operator*() { return *ps; }

        friend void swap(HasPtr&, HasPtr&);
    private:
        string* ps;
        int i ;
        
};