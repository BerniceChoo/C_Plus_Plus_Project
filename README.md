# worksheet1-ASP
Click on the following to the each task:-  
[task 1](#task1)<br />
[task 2](#task1)<br />
[task 3](#task1)<br />
[task 4](#task1)<br />

## Task 1

![allocate](image/allocate.png)

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

The string should not be duplicated by the assignment and copy operations. This is because they ought to have the same underlying memory, so changing one string updates the other, and so on.

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
![taskone](image/taskone.png)

## Task 2

## Task 3

## Task 4
