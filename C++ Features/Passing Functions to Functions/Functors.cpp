#include <iostream>
using namespace std;

struct Test {
    virtual bool operator()(string &text) = 0;
    virtual ~Test(){}
};

// A functor is a class or a struct that overloads the brackets operator
struct MatchTest : public Test {
    virtual bool operator()(string &text) {
        return text == "lion";
    }
};

void check(string text, Test &test) {
    if(test(text)) {
        cout << "Text matches!" << endl;
    }
    else {
        cout << "No match." << endl;
    }
}

// This is pre c++ 11 syntax, for lambdas
int main() {
    
    MatchTest pred;

    string value = "lion";
    cout << pred(value) << endl;


    MatchTest m;
    check("lion", m);

    return 0;
}