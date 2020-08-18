#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    // c++11 bracket initialization
    int value{5};
    cout << value << endl;

    string hello{"hi"};
    cout << hello << endl;

    int numbers[]{1,2,4};
    cout << numbers[0] << endl;

    int *pInts = new int[3]{1,2,3};
    cout << pInts[1] << endl;
    delete pInts;

    int value1{};
    cout << value1 << endl;

    int* pSomething{&value}; // assigns the address of value to this variable
    cout << *pSomething << endl;

    int *pSomething1{}; // equivalent to int *pSomething = nullptr;
    cout << pSomething1 << endl;

    int numbers1[]{}; // initializes all elements to 0;
    cout << numbers1[1] << endl;

    struct {
        int value;
        string text;
    } s1 = {5,"Hi"};

    cout << s1.text << endl;

    vector<string> strings{"one", "two", "three", "four"};
    cout << strings[2] << endl;

    
    return 0;
}