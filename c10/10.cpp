#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <numeric>
using namespace std;

int main(void) {
    //10.1 & 10.2
    vector<int> v{2,4,1,2,5,6,-1,0};
    list<int> l{2,4,1,2,5,6,-1,0};
    
    int res = std::count(v.begin(), v.end(), 2);
    cout << res << endl;
    res = std::count(l.begin(), l.end(), 2);
    cout << res << endl;
    
    // 10.3
    res = std::accumulate(v.begin(), v.end(), 0);
    cout << res << endl;
    
    return 0;
}
