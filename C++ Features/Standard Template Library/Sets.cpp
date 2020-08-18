#include<iostream>
#include<set>

using namespace std;

class Test {
    int id;
    string name;

    public:
    Test(): id(0), name("") {
    }

    Test(int id, string name): id(id), name(name) {
    }

    void print() const{
        cout << id << ": " << name << endl;
    }

    // < operator is used for identifying key for the set
    bool operator<(const Test& other) const {
        return name < other.name;
    }
};

int main() {

    set<int> numbers;
    numbers.insert({0, 1, 2});

    for(set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }

    set<int>::iterator itFind = numbers.find(0);

    if(itFind != numbers.end()) {
        cout << "Found " << *itFind << endl;;
    }

    if(numbers.count(1)) {
        cout << "Found # 1" << endl;
    }

    set<Test> tests;

    tests.insert(Test(10, "Mike"));
    tests.insert(Test(30, "Joe"));
    tests.insert(Test(20, "Sue"));
    tests.insert(Test(30, "Joe"));

    // iterator returns a const Test object so any method must be const using an iterator
    for(set<Test>::iterator it = tests.begin(); it != tests.end(); it++) {
        it->print(); 
    }

    return 0;
}