#include <iostream>

using namespace std;

void test(int value) {
    cout << value << endl;
}

int main() {
    
    test(1);

    // put parentheses around *pTest to make it a function pointer
    void (*pTest)(int) = test;

    pTest(2);

    return 0;
}