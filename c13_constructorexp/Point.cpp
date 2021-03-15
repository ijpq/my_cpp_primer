
#include "Point.h"
#include <memory>
#include<vector>
using namespace std;

Point foo_bar2(Point&);

Point global;
Point foo_bar(Point arg){
    cout<<"Point local = arg"<<endl;
    Point local = arg; 

    cout<<"local = arg"<<endl;
    local = arg;

    cout<<"foo_bar2(Point&)"<<endl;
    foo_bar2(local);

    cout<<"vector.push_back(Point)"<<endl;
    vector<Point> vec;
    vec.push_back(local);

    cout<<"new Point(global)"<<endl;
    Point *ptr = new Point(global);

    cout<<"*ptr = local"<<endl;
    *ptr = local;

    cout<<"Point pa[4]"<<endl;
    Point pa[4] = {local, *ptr};

    cout<<"Point* ps = new Point"<<endl;
    Point* ps = new Point();

    cout<<"delete ps"<<endl;
    delete ps;
    
    cout<<"return *ptr"<<endl;
    return *ptr;
}
Point foo_bar2(Point& arg){
    return arg;
}

int main(){
    int x = 5;
    Point p1(x);
    Point p2 = p1;
    cout<<"calling foo_bar(Point)"<<endl;
    foo_bar(p1);
    return 0;
}