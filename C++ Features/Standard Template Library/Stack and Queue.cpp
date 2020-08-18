#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class Test {
    string name;

    public:
    Test(string name) : name(name) {

    }

    ~Test() {
        // cout << "Object destroyed " << endl;
    }

    void print() {
        cout << name << endl;
    }
};

int main () {

    // FIFO
    stack<Test> testStack;

    testStack.push(Test("Mike"));
    testStack.push(Test("John"));
    testStack.push(Test("Sue"));

    // Test &test1 = testStack.top(); // when this object is popped off the stack you can't use it anymore. 
    // Don't use a reference if it will be needed
    // testStack.pop() // this is invalid code for test1. This object is destroyed.
    // test1.print();

    // testStack.pop();

   // Test &test2 = testStack.top();
   // test2.print();
   
    cout << "Printing Stack Contents" << endl;
    while(testStack.size() > 0) {
        Test &test = testStack.top();
        test.print();
        testStack.pop();
    }
    
    cout << endl;

    // LIFO
    queue<Test> testQueue;

    testQueue.push(Test("Mike"));
    testQueue.push(Test("John"));
    testQueue.push(Test("Sue"));

    cout << "Printing Queue contents" << endl;
    while(testQueue.size() > 0) {
        Test &test = testQueue.front();
        test.print();
        testQueue.pop();
    }

    return 0;
}