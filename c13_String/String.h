#ifndef STRING_H
#define STRING_H

#include<memory>
#include<iostream>
#include<cstring>

using namespace std;
class String{
private:
    size_t sz;
    static allocator<char> alloc;
    char* elements;
    char* first_free;
    char* cap;
    
    // void reallocate(size_t);
    // pair<char*, char*> alloc_n_copy(const char*, const char*);
    // void chk_n_alloc();
    size_t size();
    
public:
    String():elements(nullptr), first_free(nullptr), cap(nullptr){
        
    };

    String(const char* s):sz(std::strlen(s)),elements(alloc.allocate(sz)){
        first_free = cap = std::uninitialized_copy(s, s+sz, elements);
    }

    String(const String& str){ //copy
        cout<<"copy constructor";
        for (auto x = str.elements; x!=str.first_free;++x) cout<<*x;
        cout<<endl;
        elements = alloc.allocate(str.first_free-str.elements);
        cap = first_free = uninitialized_copy(str.elements, str.first_free, elements);
    }


    String& operator=(const String& str){ //copy
        cout<<"copy operator= overload";
        for (auto x = str.elements; x!=str.first_free;++x) cout<<*x;
        cout<<endl;
        if (this!=&str){
            free();
            elements = alloc.allocate(str.first_free - str.elements);
            cap = first_free = uninitialized_copy(str.elements, str.first_free, elements);
        }

    }

    String(String&& str) noexcept{
        cout<<"move constructor ";
        for (auto x=str.elements; x!=str.first_free;++x){
            cout<<*x;
        }
        cout<<endl;
        this->elements = str.elements;
        this->cap = str.cap;
        this->first_free = str.first_free;
        str.elements = str.first_free = str.cap = nullptr;
    }    

    String& operator=(String&& str) noexcept{ //move
        cout<<"move operator= overload";
        for (auto x = str.elements;x!=str.first_free;++x) cout<<*x;
        cout<<endl;
        if(this!=&str){
            
            free();
            this->elements = str.elements;
            this->first_free = str.first_free;
            this->cap = str.cap;
            str.cap = str.elements = str.first_free = nullptr;
        }
    }

    // void push_back(const char&);
    // void chk_alloc();

    void free();
    ~String();
    
};

inline
size_t String::size(){
    return this->first_free-this->elements;
}

// inline
// void String::push_back(const char& ch){
//     auto newdata = alloc.allocate(this->first_free-this->elements+1);
    
//     auto elem = this->elements;
//     auto dest = newdata;
//     // for (auto i = 0; i<size();++i){
//     //     alloc.construct(dest++, std::move(*elem++));
//     // }
//     alloc.construct(dest++, std::move(ch));
//     free();
//     this->elements = newdata;
//     this->first_free = this->cap = dest;
// }


#endif
