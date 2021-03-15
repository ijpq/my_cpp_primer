#include<vector>
#include<string>
#include <iostream>
#include <string>
#include <ostream>

using namespace std;

class Window_mgr{
public:
    typedef vector<Screen>::size_type ScreenIndex;
    void clear(ScreenIndex);
private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};


class Screen{
    public:
        typedef std::string::size_type size_int;
        Screen() = default;
        Screen(size_int h, size_int w, char c):
            height(h), width(w), contents(h*w,c){}
        Screen(size_int h, size_int w):
            height(h), width(w), contents(h*w, ' '){}

        Screen& move(size_int r, size_int c){
            size_int row = r * width;
            cursor = row+c;
            return *this;
        }
        char get(size_int r, size_int c) const {
            size_int row = r*width;
            return contents[row+c];
        }
        Screen& set(char c){
            this->contents[cursor] = c;
            cout<<"using this ptr :"<<this->contents[cursor]<<endl;
            contents[cursor] = c;
            cout<<"not using this ptr:"<<contents[cursor]<<endl;
            return *this;
        }
        
        Screen& display(ostream& os){
            os<<"calling non const member func"<<endl;
            do_display(os);
            return *this;
        }

        const Screen& display(ostream& os) const{
            os<<"calling const member func"<<endl;
            do_display(os);
            return *this;
        }

        friend void Window_mgr::clear(ScreenIndex);
        
    private:
        size_int cursor=0;
        size_int height = 0, width = 0;
        string contents;
        void do_display(ostream& os) const
        {
            os<<contents<<endl;
        }
};

void Window_mgr::clear(ScreenIndex idx){
    Screen& s = screens[idx];
    s.contents = string(s.height * s.width, ' ');
    return ;
}


