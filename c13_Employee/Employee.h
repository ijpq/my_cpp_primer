
#include <string>

using namespace std;

class Employee{
private:
    string name = "";
    static int global_id;
    int id =0;
public:
    Employee(){
        name = "";
        id = global_id++;
    };
    Employee(string& name_str):name(name_str){
        id = global_id++;
    }
    Employee(const Employee& emp){
        name = emp.name;
        id = global_id++;
    }

    Employee& operator=(const Employee& emp){
        if (this != &emp){
            name = emp.name;
            id = global_id++;
        }
        return *this;
    }
};

