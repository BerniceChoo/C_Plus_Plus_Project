# worksheet1-ASP
Click on the following to the each task:-  
[Task 1](#task-1)<br />
[Task 2](#task-2)<br />
[Task 3](#task-3)<br />
[Task 4](#task-4)<br />

## Task 1

```
private:
    char * str_; // to allocate dynamic memory for the string
    int * counter;

public:

    my_string(){
    }
```

The implementation is compatible with strings of any length, because it employs dynamic memory allocation to create a duplicate of any string data provided in construction or via assignment.  

```
#include"my_string.hpp"

int main() {
    my_string s("Hello world");
    s.print(); 
    {
       my_string t = s;
       s.print();
       t.print();
       std::cout << s.getChar(1) << std::endl;
       s.print();
       t.print();
    }
    s.setChar(1,'E');
    s.print();
}
```

The string should not be duplicated by the assignment and copy operations. This is because they ought to have the same underlying memory, so changing one string updates the other.

```
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
```
the output of task 1:-
![taskone](images/taskone.png)

## Task 2

counter is added in this task because it will be use to indicate the string printed. The string implementation is extended to support automatic reference counting. A key element of this is that the interface for my_string did not have any changes but, the destructor ~my_string()free the allocated memory when the reference count is 0. Therefore, it will delete the string when there are no remaining references to the object.

```
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

```

Counter is added one because in string the first character starts from 0. Therefore, to make the first character 1, it has to plus 1.

![tasktwo](images/tasktwo.png)

## Task 3
Extend the example test program to demostrate when the case of a reference count of 0 where it free the allocated memory.

```
~my_string() { // free the allocated memory
        //delete[] str_;
        *counter = *counter-1; 

        if (*counter==0){ // ONLY when the reference count is 0
            std::cout << "Refenrence counter = 0 ,hence deleting object : " << str_ << std::endl; //print demostration for task 3
            delete str_; //it will delete the object, when the case of a reference count is 0
            delete counter; // delete counter, when the case of a reference count is 0
        }
    }
```
When the reference count is 0, it will conduct the IF statement which will delete the object and counter.

![taskthree](image/taskthree.png)

## Task 4

point

![testtaskfour](image/testtaskfour.png)

![taskfour](image/taskfour.png)

