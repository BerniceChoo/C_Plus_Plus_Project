#include <iostream>
#include <cstring>

using namespace std;

class my_string {

private:
    char * str_; // to allocate dynamic memory for the string
    int * counter;

public:

    my_string(){
        
    }

    my_string(const char* str) {
        str_ = new char[strlen(str) + 1]; // dynamic memory allocation
        strcpy(str_, str);
        counter = new int; // dynamic memory allocation
        *counter = 1;
    }

    my_string(my_string const& s) {
        this-> str_ = s.str_; // use "this->" because it refers to the current instance of the class.
        this-> counter=s.counter;
        *counter = *counter + 1; // counter plus one because in string the first character starts from 0
        //Therefore, to make the first character 1, it has to plus 1
    }

    my_string& operator= (my_string const& s){
        if (this == &s)
        {
            return *this; // return counter
        }

        this-> str_ = s.str_;
        this-> counter=s.counter; //to support automatic reference counting
        *counter = *counter + 1; //counter plus one because in string the first character starts from 0
        return *this; // return counter
    }

    ~my_string() { // free the allocated memory
        //delete[] str_;
        *counter = *counter-1; 

        if (*counter==0){ // ONLY when the reference count is 0
            std::cout << "Refenrence counter = 0 ,hence deleting object : " << str_ << std::endl; //print demostration for task 3
            delete str_; //it will delete the object, when the case of a reference count is 0
            delete counter; // delete counter, when the case of a reference count is 0
        }
    }

    char getChar(const int& i){
        return str_[i]; // retrun string
    }
    const

    void setChar(const int& i, const char& c){
        str_[i] = c;
    }
    void print() {
        std::cout << str_ << " " << "[" <<*counter << "]" << std::endl; //print statement
    }
};