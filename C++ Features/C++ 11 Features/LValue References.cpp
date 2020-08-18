#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Test {
private:
    static const int SIZE = 100;
    int *_pBuffer;
public:
    Test() {
        cout << "constructor" << endl;
        //_pBuffer = new int[SIZE];
        // memset(_pBuffer, 0, sizeof(int)*SIZE); old way of initializing all of array to 0
        _pBuffer= new int[SIZE]{}; // c++ 11 way of zeroizing array
    }

    // in c++11 you can call another constructor. in c++98 you will have an init method that all the differe
    // constructors can call.
    Test(int i) {
        cout << "paremeterized constructor" << endl;
        _pBuffer= new int[SIZE]{}; // c++ 11 way of zeroizing array

        for(int i = 0; i < SIZE; i++) {
            _pBuffer[i] = 7 * i;
        }

    }

    Test(const Test &other) {
        cout << "copy constructor" << endl;

        _pBuffer= new int[SIZE]{}; // c++ 11 way of zeroizing array

        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
    }

    Test &operator=(const Test &other) {
        cout << "assignment" << endl;

        _pBuffer = new int[SIZE]{};

        memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
        return *this;
    }

    ~Test() {
        cout << "destructor" << endl;
        delete [] _pBuffer;
    }

    friend ostream &operator<<(ostream &out, Test &test);
};

ostream &operator<<(ostream &out, Test &test) {
    out << "Hello from test";
    return out;
}

Test getTest() {
    return Test();
}

int main() {

    // eliding is performed here by the compiler to get rid of extra object copies.
    Test test1 = getTest();

    cout << test1 << endl;

    // leads to 2 extra destructor calls even with optimization. Will be addressed in "Rvalue References.cpp"
    vector<Test> vec;
    vec.push_back(Test());

    Test &rTest1 = test1;

    // Test &rTest2 = getTest(); // doesn't work because it returns an rvalue
    const Test &rTest2 = getTest(); // this does work b/c lifetime is extended due to const

    // This works because const lvalue references can bind to rvalues
    Test test2(Test(1)); // test2 is lvalue, Test(1) is rvalue

    return 0;
}