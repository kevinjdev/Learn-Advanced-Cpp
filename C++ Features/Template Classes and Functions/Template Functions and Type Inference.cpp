#include <iostream>
using namespace std;

template<class T>
void print(T n) {
    cout << "Template Version " << n << endl;
}

void print(int value) {
    cout << "Non-template version: " << value << endl;
}

template<class T>
void show() {
    cout << T() << endl;
}

int main() {

    print<string>("Hello");
    print<int>(5);
    print("Hi there");
    //print<>(6); // will use the template version of the function
    print(6);

    show<int>();
    
    return 0;
}