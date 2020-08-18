#include <iostream>

using namespace std;

class Test {
    private:
    string name;
    int id;

    public:
    Test() : id(0), name("") {}

    Test(int id, string name) : name(name), id(id) {}
    
    void print() {
        cout << id << ": " << name << endl;
    }

    // Rule of 3 in C++. If you implement a copy constructor, assignment operator or destructor, you should implement all 3.
    // If you have pointers in your object, you don't want to do a shallow copy so you need to implement your own functionality
    const Test &operator=(const Test &other) {
        cout << "Assignment running" << endl;
        id = other.id;
        name = other.name;
        return *this;
    }

    Test(const Test& other) {
        cout << "Copy constructor running" << endl;
        //id = other.id;
        //name = other.name;
        *this = other; // you can use the assinment operator in the Copy constructor
    }
    
    ~Test() {

    }


};

int main() {
    
    Test test1(10, "Mike");
    cout << "Print test1: " << flush;
    test1.print();
    Test test2(20, "Bob");
    cout << "Print test2: " << flush;
    test2.print();

    test2 = test1;
    test2.print();

    Test test3; 
    // test3 = test2 = test1; // think of equals as a method call and it returns a reference to test 2 then sets test3 to a reference test2

    test3.operator=(test2);
    cout << "Print test3" << flush;
    test3.print();

    cout << endl;
    // Copy initialization. We are invoking the implicit copy constructor, not the assignment operator
    Test test4 = test1;
    test4.print();
    return 0;
}