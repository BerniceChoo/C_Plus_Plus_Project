#include <iostream>
#include <cstring>

using namespace std;

class my_string {

private:
    char * str_;
    int * counter;

public:

    my_string(){
        
    }

    my_string(const char* str) {
        str_ = new char[strlen(str) + 1];
        strcpy(str_, str);
        counter = new int;
        *counter = 1;
    }

    my_string(my_string const& s) {
        this-> str_ = s.str_;
        this-> counter=s.counter;
        *counter = *counter + 1;
    }

    my_string& operator= (my_string const& s){
        if (this == &s)
        {
            return *this;
        }

        this-> str_ = s.str_;
        this-> counter=s.counter;
        *counter = *counter + 1;
        return *this;
    }

    ~my_string() { // task 3
        //delete[] str_;
        *counter = *counter-1;

        if (*counter==0){
            std::cout << "Refenrence counter ==0 ,hence deleting object :" << str_ << std::endl;
            delete str_;
            delete counter;
        }
    }

    char getChar(const int& i){
        return str_[i];
    }
    const

    void setChar(const int& i, const char& c){
        str_[i] = c;
    }
    void print() {
        std::cout << str_ << " " << "[" <<*counter << "]" << std::endl;
    }
};