#include <iostream>
using namespace std;

class Test {

};

template<typename T>
void call(T &&arg) {
    // check(static_cast<T>(arg)); // need to use static cast for this to work properly
    check(forward<T>(arg)); // can also use forward instead
}

void check(Test &test) {
    cout << "lvalue" << endl;
}

void check(Test &&test) {
    cout << "rvalue" << endl;
}

int main() {
    Test test;

    call(test); // lvalue
    call(Test()); // rvalue

    return 0;
}