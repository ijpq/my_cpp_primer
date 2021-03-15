
#include <memory>

#include<iostream>
using namespace std;


class Point{

public:
    Point(const Point& p){
        cout<<"value of this->data:"<<this->data<<endl;
        cout<<"calling copy constructor"<<endl;
        this->data = p.data;
        cout<<"after calling: this->data:"<<this->data<<endl;
    }
    Point(Point&&) noexcept;
    // Point (Point&& pp) noexcept{
    //     cout<<"value of this->data:"<<this->data<<endl;
    //     cout<<"calling move constructor"<<endl;
    //     this->data = pp.data;
    //     cout<<"after calling: this->data:"<<this->data<<endl; 
    // }
    Point(){
        cout<<"default constructor"<<endl;
        this->data = 10; //default
    }
    Point(int d):data(d){
        cout<<"calling constructor"<<endl;
    }
    Point& operator=(Point && pmove) noexcept{
        cout<<"move overload"<<endl;
        return *this;
    }
    Point& operator=(const Point& pcopy){
        cout<<"copy overload"<<endl;
        return *this;
    }
    ~Point(){
        cout<<"deconstructor"<<endl;
    }
    Point foo_bar(Point);
private:
    int data = 0;
};

inline Point::Point(Point&& pp) noexcept{
    cout<<"move"<<endl;
}