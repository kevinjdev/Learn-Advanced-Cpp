#include <iostream>
using namespace std;

class Parent {
};

class Brother: public Parent {

};

class Sister : public Parent {

};

int main() {
    Parent parent;
    Brother brother;
    Sister sister;

    float value = 3.23;

    cout << (int)value << endl; //c-style cast
    cout << int(value) << endl; //c++ c-style cast

    cout << static_cast<int>(value) << endl;

    Parent *pb = &brother; // this works and is a principle of polymorphism (using subclass where a superclass is expected)
    Brother *bb = static_cast<Brother*>(&parent); // this works but is very bad and you shouldn't cast a child to a parent


    Brother *pbb = static_cast<Brother *>(pb); // this works but is also very bad. It will compile but could crash

    Parent &&p = Parent(); // Calling constructor results in rvalue

    Parent &&pp = static_cast<Parent &&>(parent); // this works to pass lvalue to rvalue by using static cast

    cout << bb << endl;


    return 0;
}