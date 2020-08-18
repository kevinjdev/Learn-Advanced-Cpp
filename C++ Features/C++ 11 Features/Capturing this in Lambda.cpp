#include <iostream>
using namespace std;

class Test {
    private:
    int one{1};
    int two{2};

    public:
    void run() {
        int three{3};
        int four{4};

        auto pLambda = [this, three, four](){
            cout << three << " " << four << endl; // local variables
            cout << one << endl; // this is captured by this(by reference) as an instance variable
        };
        pLambda();
    }
};

int main() {
    Test test;
    test.run();

    return 0;
}

