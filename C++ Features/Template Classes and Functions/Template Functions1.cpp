#include <iostream>
using namespace std;

template<class T>
// tempate<typename T> //also valid
void print(T n) {
    cout << n << endl;
}

int main() {
    print<int>(5);
    print<string>("Hello");
    print("Hello there");
    return 0;
}