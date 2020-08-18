#include <iostream>
using namespace std;

class Parent {
public:
    virtual void speak() {
        cout << "paarent!" << endl;
    }
};

class Brother: public Parent {

};

class Sister : public Parent {

};

int main() {
    Parent parent;
    Brother brother;
    Sister sister;

    Parent *ppb = &parent;

    // this will return a null ptr due to casting a superclass. This is safer than static_cast due to runtime checking
    Brother *pbb = dynamic_cast<Brother *>(ppb); 
    if(pbb = nullptr)
    {
        cout << "Invalid cast" << endl;
    } else {
        cout << pbb << endl;
    }

    return 0;
}