#include <iostream>
using namespace std;

int main() {

    int one = 1;
    int two = 2;
    int three = 3;

    // the square brackets allow you to capture local variables by value
    [one, two](){cout << "hello" << endl; }(); // the final parentheses call the lambda immediately
    
    // captures all local values by value (one, two, three)
    [=](){cout << "hello" << endl; }();

    // captures all local values by value but capture 3 by reference
    [=, &three](){cout << "hello" << endl; }();

    // captures all local values by reference
    [&](){three = 7; two = 8; cout << one << endl; }();

    // captures all local values by reference, but capture 3 by value
    [&, three](){one=100; cout << one << endl; }();






    
    return 0;
}