#include <iostream>
using namespace std;

void test(void (*pFunc)() ) {
    pFunc();
}

int main() {
    
    // lambda details
    [/*signified this is a lambda*/](/*parameters*/){/*code goes here*/}; 

    // This is the most simple lambda expression
    [](){};

    auto func = [](){ cout << "Hello" << endl; };

    func(); // this is a functor but the details vary

    test(func);

    test([](){ cout << "Hello again" << endl; });




    
    return 0;
}