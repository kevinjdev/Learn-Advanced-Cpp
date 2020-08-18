#include <iostream>
using namespace std;

int main() {

    int cats = 5;
    // the mutable keyword allows you to change the value of captured parameters
    [cats]() mutable{ cats = 8; cout << cats << endl; }();

    cout << cats << endl;

    return 0;
}