#include <iostream>
#include <typeinfo> // for using typeid
using namespace std;

int main() {
    string value;
    
    cout << typeid(value).name() << endl; //typeid is c++98
    
    decltype(value) name = "Bob"; // c++11 decltype(value) returns string
    
    cout << typeid(value).name() << endl;

    cout << name << endl;
    
    return 0;
}