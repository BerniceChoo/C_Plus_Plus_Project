#include <iostream>
#include <cstring>

using namespace std;

class my_string {
    char * str_;
public:

    my_string();
    my_string(const char* str) {
        str_ = new char[strlen(str) + 1];
        strcpy(str_, str);
    }

    my_string(my_string const& s);
    my_string& operator= (my_string const& s);
    ~my_string() {
        
    }

    char getChar(const int& i) const;
    void setChar(const int& i, const char& c);
    void print() {
        std::cout << str_ << std::endl;
    }
};