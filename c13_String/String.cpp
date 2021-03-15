#include "String.h"
#include<vector>
using namespace std;

allocator<char> String::alloc;
inline
void String::free(){
    while (this->first_free != this->elements){
        this->alloc.destroy(--first_free);
    }
    alloc.deallocate(this->elements, this->cap-this->elements);
}

inline
String::~String(){
    free();
}

int main(){
    
    vector<String> vecStr;
    String s1("s1"), s2("s2");
    // String s3(s2);
    // s3 = s1;
    // s3 = String("s3");
    vecStr.push_back(s1);
    vecStr.push_back(std::move(s2));
    vecStr.push_back(String("s3"));
    vecStr.push_back("s4");
    return 0;
}