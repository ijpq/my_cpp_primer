#include <set>
#include "sales_data.h"
#include <iostream>
using namespace std;
bool CompareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

class cmp {
public:
    bool operator ()(const Sales_data &lhs, const Sales_data &rhs) {
        return (lhs.isbn() < rhs.isbn());
    }
};

bool operator <(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main(void) {

    // cpp primer 方法1
    std::multiset<Sales_data, decltype(CompareIsbn)*> bookstore(&CompareIsbn);

    // cpp primer 方法2
    using ptr_CompareIsbn = bool (*) (const Sales_data &lhs, const Sales_data &rhs);
    std::multiset<Sales_data, ptr_CompareIsbn> bookstore(&CompareIsbn);

    // 函数对象实现
    std::multiset<Sales_data, cmp> bookstore;

    //关系运算符重载
    std::multiset<Sales_data> bookstore;
    
    bookstore.emplace(string("ZZZ"));
    bookstore.emplace(string("AAA"));
    for (auto i = bookstore.begin(); i != bookstore.end(); i++) {
        cout << i->isbn()  << endl;
    }
    return 0;
}