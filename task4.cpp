#include"task4.hpp"
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    //Point p1(5,2);
    //p1.display();

    // Referencecounter<Point> p1 (new Point(4,3));
    // cout << "Point counter:" << p1.get_counter() << endl;

    // {Referencecounter<Point> p2 (p1);
    // cout << "Point counter:" << p1.get_counter() << endl;
    // }

    Referencecounter<my_string> string1 (new my_string("Hello world"));
    string1 ->print();
    cout << "String counter:" << string1.get_counter() << endl;

    {Referencecounter<my_string> string2(string1); // new obj t value =s

    string1 ->print();
    cout << "String counter:" << string1.get_counter() << endl;

    string2->print();
    cout << "String counter:" << string1.get_counter() << endl;
    cout << string1-> getChar(1) << endl;

    string1 ->print();
    cout << "String counter:" << string1.get_counter() << endl;

    string2->print();
    cout << "String counter:" << string1.get_counter() << endl;
    }
    
    string1->setChar(1,'E');
    string1 ->print();
    cout << "String counter:" << string1.get_counter() << endl;
}