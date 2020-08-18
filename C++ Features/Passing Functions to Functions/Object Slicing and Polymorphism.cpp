#include <iostream>
using namespace std;

class Parent {
    private:
    int one;
    public:
    Parent() : one(0) {

    }
    Parent(const Parent &other) {
        cout << "copy parent" << endl;
    }
    void print() {
        cout << "parent" << endl;
    }
    virtual void print1() {
        cout << "parent" << endl;
    }
};

class Child: public Parent {
    private:
    int two;
    public:
    Child() : two(0) {}

    void print() {
        cout << "child" << endl;
    }

    void print1() {
        cout << "child" << endl;
    }
};

int main() {
    Child c1;
    Parent &p1 = c1;
    p1.print(); // because print isn't virtual then there is no lookup table to print the child print function
    
    Child c2;
    Parent &p2 = c2;
    p2.print1(); // using virtual

    Parent p3 = Child(); // invokes implicit copy constructor for the parent. If you define a constructor in the parent you must
    // make sure to create a default constructor in the parent or define which constructor to run when you instantiate a child object.
    // the variable two gets removed due to object slicing b/c it is part of child and not parent.
    p3.print1();

    return 0;
}