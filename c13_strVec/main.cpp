#include"TextQuery.h"
#include<iostream>
#include<string>
#include<fstream>
#include <memory>
#include"strVec.h"
using namespace std;

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main()
{
    std::ifstream file("./file.txt");
    runQueries(file);
    return 0;
}
