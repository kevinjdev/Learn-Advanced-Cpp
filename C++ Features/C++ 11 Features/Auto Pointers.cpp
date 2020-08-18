#include <iostream>
#include <memory>

using namespace std;

class Test {
    public:
    Test() {
        cout << "Test Created" << endl;
    }

    void greet() {
        cout << "Hello" << endl;
    }

    ~Test() {
        cout << "destroyed" << endl;
    }
};

class Temp {
    private:
    unique_ptr<Test[]> pTest;

    public:
    Temp(): pTest(new Test[2]){}
};

int main() {


    // auto_ptr can be used prior to C++11 but it is deprecated
    { // brackets used to change scope
    unique_ptr<Test> pTest(new Test);

    pTest->greet();
    }

    cout << "Finished" << endl;

    Test test;

    return 0;
}