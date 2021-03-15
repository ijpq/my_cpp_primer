
#include<string>
#include<memory>
using namespace std;

class HasPtr{
public:
    HasPtr(const string& s = string()){
       ps = new string(s);
       i = 0;
       ps_cnt = new size_t(1); 
    }
    HasPtr(const HasPtr& p){
        
        ps = p.ps;
        ps_cnt = p.ps_cnt;
        (*ps_cnt)++;
        i = p.i;
    }
    HasPtr& operator=(const HasPtr& pp){
        (*ps_cnt)--;
        (*pp.ps_cnt)++;
        if (!ps_cnt){
            delete ps_cnt;
            delete ps;
        }
        ps = pp.ps;
        i = pp.i;
        ps_cnt = pp.ps_cnt;
        return *this;
    }
    ~HasPtr(){
        --*ps_cnt;
        if (!*ps_cnt){
            delete ps_cnt;
            delete ps;
        } 
    }
private:
    string* ps = nullptr;
    size_t* ps_cnt;
    int i ;
};