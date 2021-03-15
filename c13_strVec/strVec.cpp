
#include <string>
#include "strVec.h"
#include <memory>
#include <iostream>

using namespace std;
std::allocator<std::string> strVec::alloc;

strVec::strVec(const strVec& strvec){ // copy constructor
        pair<string*, string*> p = alloc_n_copy(strvec.elements, strvec.cap);
        this->elements = p.first;
        this->first_free = p.second;
        this->cap = p.second;
    };


void strVec::push_back(const string& s){
    chk_n_alloc();
    alloc.construct(first_free++, s);
    // return ;
};

void strVec::free(){
    if (elements){
        for (auto ptr = first_free; ptr != elements; ){
            alloc.destroy(--ptr);
        }
        alloc.deallocate(elements, cap-elements); // destroy() has called deconstructor to free the memory. why we call deallocate() to free the memory again?
    }
}

strVec::~strVec() { free();}

void strVec::reallocate(size_t n = 0){
    auto newcapacity = size()? 2*size():1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata; // ptr to first element of new memory
    auto elem = elements; // ptr to first element of old memory
    for (auto i =0; i < size();++i){
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    cap = elements + newcapacity;
    first_free = dest;
    return ;
}

strVec& strVec::operator=(const strVec& strvec){
        auto data = alloc_n_copy(strvec.begin(), strvec.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    };

pair<string*, string*> strVec::alloc_n_copy(const string* a, const string* b){
        auto data = alloc.allocate(b-a);
        return {data, uninitialized_copy(a,b,data)};
    }

void strVec::chk_n_alloc(){
        if (size() == capacity()) 
            reallocate();
    }

void strVec::reverse(size_t n) {
    if (n <= size() || n <= capacity()) return;

    reallocate(n);
    // else {
    //     auto newdata = alloc.allocate(n);
    //     auto dest = newdata;
    //     auto elem = elements;
    //     for ( auto i = 0; i < n; ++i){
    //         alloc.construct(dest++, std::move(*elem++));
    //     }
    //     free();
    //     elements = newdata;
    //     cap = elements + n;
    //     first_free = dest;
    // }
    return ;
}

void strVec::resize(size_t n, const string& s=""){
    // comp with size, rather than capacity().
    if (n == size()) return ;
    else if (n > capacity()) {
        reallocate(n);
        // auto newcapacity = n;
        // string* dest = alloc.allocate(newcapacity);
        // string* elem = elements;
        // for (size_t i = 0; i < n; ++i)
        // {
        //     alloc.construct(dest++, std::move(*elem++));
        // }
        // free();
        // elements = elem;
        // first_free = dest;
        // cap = elements + newcapacity;
    }
    else if(n > size()){
        for ( int i =0; i<size()-n ;++i)
            push_back(s);
    }
    else { // n < size()
        for (; size() != n;){
            alloc.destroy(--first_free);
        }
        // alloc.deallocate(first_free, cap-first_free);
        // chk_n_alloc();
    }
    return ;
}



// int main(){
//     cout<<"main function in strVec.cpp"<<endl;
//     auto *p = new strVec;
//     string s = "saf";
//     p->push_back(s);
//     return 0;
// }