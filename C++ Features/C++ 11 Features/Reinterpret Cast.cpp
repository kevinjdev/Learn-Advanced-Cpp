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

    Parent *ppb = &brother;

    // This returns nullptr with dynamic cast but will work with reinterpret cast. However you should rarely use it.
    Sister *pbb = reinterpret_cast<Sister *>(ppb); 
    if(pbb = nullptr)
    {
        cout << "Invalid cast" << endl;
    } else {
        cout << pbb << endl;
    }

    return 0;
}