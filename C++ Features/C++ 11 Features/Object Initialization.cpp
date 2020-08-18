#include <iostream>
using namespace std;

class Test {
    private:
    int id{3};
    string name{"Mike"};

    public:
    Test() = default;
    Test(const Test &other) = default; // copy constructor. Can undo this with the delete keyword
    Test &operator=(const Test &other) = default; // assignment operator
    Test(int id) : id(id) {}
    void print() {
        cout << id << ": " << name << endl;
    }
};

int main() {
    Test test;
    test.print();

    Test test1(1);
    test1.print();

    Test test2 = test1; //calls copy constructor
    Test test3 = test; // calls assignment constructor
    return 0;
}