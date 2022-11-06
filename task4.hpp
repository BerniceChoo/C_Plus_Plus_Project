#include <iostream>
#include <cstring>
using namespace std;

class Point{

    private:
        int x; // create object
        int y;

    public:
        Point(int const& x, int const& y){
            this->x = x; //use "this->" because it refers to the current instance of the class.
            this->y = y;
        }

        void display(){
            cout << "X = " << x << ", Y = " << y << endl; // print points

        }
};

template <typename T> // template function_declaration
class Referencecounter{

    private:
        T* data;
        int * counter;

    public:
        Referencecounter(): data(), counter(new int (0)){

        }
        Referencecounter(T * data) : data(data), counter(new int (1)){

        }

        Referencecounter(Referencecounter const& obj){
            this-> data = obj.data;
            this-> counter=obj.counter;
            *counter = *counter + 1;
        }

        Referencecounter& operator= (Referencecounter const& obj){

            if (this== &obj){
                return *this;
            }            
            this-> data = obj.data;
            this-> counter=obj.counter;
            *counter = *counter + 1;
            return *this;
        }

        T* operator->(){
            return this->data;
        }

        int get_counter(){
            return *counter;
        }

        ~Referencecounter(){
            *counter = *counter-1;
            if (*counter == 0){
                delete data;
                delete counter;
            }
        }
};

class my_string {

private:
    char * str_;

public:

    my_string(){
        
    }

    my_string(const char* str) {
        str_ = new char[strlen(str) + 1];
        strcpy(str_, str);
    }

    my_string(my_string const& s) {
        this-> str_ = s.str_;
    }

    my_string& operator= (my_string const& s){
        if (this == &s)
        {
            return *this;
        }

        this-> str_ = s.str_;
        return *this;
    }

    ~my_string() {
        delete str_;
    }

    char getChar(const int& i){
        return str_[i];
    }
    const

    void setChar(const int& i, const char& c){
        str_[i] = c;
    }
    void print() {
        cout << str_ << endl;
    }
};