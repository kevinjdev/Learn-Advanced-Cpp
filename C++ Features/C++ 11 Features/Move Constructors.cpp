#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Test {
private:
    static const int SIZE = 100;
    int *_pBuffer{nullptr};
public:
    Test() {
    
        //_pBuffer = new int[SIZE];
        // memset(_pBuffer, 0, sizeof(int)*SIZE); old way of initializing all of array to 0
        _pBuffer= new int[SIZE]{}; // c++ 11 way of zeroizing array
    }

    // in c++11 you can call another constructor. in c++98 you will have an init method that all the differe
    // constructors can call.
    Test(int i) {

        _pBuffer= new int[SIZE]{}; // c++ 11 way of zeroizing array

        for(int i = 0; i < SIZE; i++) {
            _pBuffer[i] = 7 * i;
        }

    }

    Test(const Test &other) {

        _pBuffer= new int[SIZE]{}; // c++ 11 way of zeroizing array

        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
    }

    // move constructor
    Test(Test &&other) {
        cout << "Move constructor" << endl;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;
    }

    Test &operator=(const Test &other) {

        _pBuffer = new int[SIZE]{};

        memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
        return *this;
    }

    ~Test() {

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

    vector<Test> vec;
    vec.push_back(Test()); //Don't have to allocate memory with the move constructor
    return 0;
}