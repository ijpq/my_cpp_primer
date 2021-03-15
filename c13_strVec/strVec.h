#ifndef STRVEC_H
#define STRVEC_H
#include<memory>
#include <string>
#include<initializer_list>

using namespace std;

class strVec{
private:
    // shared_ptr<string> elements = make_shared<string>();
    // shared_ptr<string> first_free = make_shared<string>();
    // shared_ptr<string> cap = make_shared<string>();
    static allocator<string> alloc;
    std::string *elements;
    std::string *first_free;
    std::string *cap;
    void free();
    void reallocate(size_t);
    pair<string*, string*> alloc_n_copy(const string* a, const string* b);
    void chk_n_alloc();
    
public:
    //constructor
    strVec():elements(nullptr),first_free(nullptr),cap(nullptr){}; //default
    strVec(const strVec& strvec);
    strVec(initializer_list<string> list){
        auto newdata = alloc_n_copy(list.begin(), list.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
    };

    //move constructor
    strVec(strVec&& strvec) noexcept :elements(strvec.elements),first_free(strvec.first_free),cap(strvec.cap){
        strvec.elements = strvec.first_free = strvec.cap = nullptr;
    }
    
    strVec& operator=(strVec&& strvec) noexcept{
        if (this != &strvec){
            free();
            elements = strvec.elements;
            first_free = strvec.first_free;
            cap = strvec.cap;
            strvec.elements = strvec.first_free = strvec.cap = nullptr;
        }
        return *this;
    }
    strVec& operator=(const strVec& strvec);
    //destructor
    ~strVec();
    void push_back(const string& s);

    string* begin() const {return elements;}
    string* end() const {return first_free;}

    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap-elements;}
    void reverse(size_t);
    void resize(size_t, const string&);
    
};



#endif