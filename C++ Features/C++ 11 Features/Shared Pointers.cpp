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

// shared pointers don't delete the memory associated with your objects until all the objects
// are out of scope. You can't use shared pointers with arrays
int main() {

    shared_ptr<Test> pTest2(nullptr);

{
    // the best way to use shared_ptr is using make_shared
    shared_ptr<Test> pTest1 = make_shared<Test>();

    pTest2 = pTest1;

}

    cout << "Finished" << endl;
    
    return 0;
}