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

void check(const Test &value) {
    cout << "lValue function" << endl;
}

void check(Test &&value) {
    cout << "rValue function" << endl;
}

int main() {

    // eliding is performed here by the compiler to get rid of extra object copies.
    Test test1 = getTest();

    cout << test1 << endl;

    // leads to 2 extra destructor calls even with optimization. Will be addressed in "Rvalue References.cpp"
    vector<Test> vec;
    vec.push_back(Test());

    //int value1 = 7; // 7 is an rvalue, value1 is a lvalue

    //int *pValue1 = &value1;
    // int *pValue2 = &7 // 7 is an rvalue and you can't take an address of an rvalue

    //Test *pTest1 = &test1;
    // Test *pTest2 = &getTest(); // this doesn't work because the return value is an rValue which is a temporary value

    //int *pValue3 = &++value1; // prefix operator works
    //cout << *pValue3 << endl;

    // int *pValue4 =&value1++; //postfix doesn't work b/c of creation of temporary value and modifying rValue.
    // int *s = &(7 + value1); // not valid

    // lvalue reference
    Test &ltest1 = test1;

    // rvalue reference
    Test &&rtest1 = Test();
    Test &&rtest2 = getTest();

    // Can differentiate between temporary and non-temporary values

    check(test1);
    check(getTest());
    check(Test());

    // You can't take address of Rvalues. Functions usually return Rvalues



    return 0;
}