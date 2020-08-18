#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

int add(int a, int b, int c) {
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
}

class Test {
public:
    int add(int a, int b, int c) {
        cout << a << ", " << b << ", " << c << endl;
        return a + b + c;
    }
};

int run(function<int(int,int)> func) {
    return func(7,3);
}
 
// bind allows you to create aliases to functions
int main() {

    cout << add(1,2,3) << endl;

    auto calculate = bind(add, 3,4,5);

    auto calculate1 = bind(add, _1, _2, _3); // these are placeholders

    auto calculate2 = bind(add, _2, _3, _1); // changes the order of parameters to a function

    auto calculate3 = bind(add, _1, 100, _2); // one fixed parameter

    // using a class method
    Test test;

    auto calculate4 = bind(&Test::add, test, 1,2,3);

    cout << calculate() << endl;

    cout << calculate1(10,20,30) << endl;

    cout << calculate2(10,20,30) << endl;

    cout << calculate3(10,20) << endl;

    cout << run(calculate3) << endl;

    cout << calculate4() << endl;

    return 0;
}