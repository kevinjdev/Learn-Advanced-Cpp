#include <iostream>
using namespace std;

class Parent {
    private:
    int dogs;
    string text;

    public:
    // This is constructor delegation in c++11 which allows you choose a constrcutor to be called
    Parent() : Parent("hello") {
        dogs=5;
        cout << "No parameter paretn constructor" << endl;
    }

    Parent(string text) {
        dogs = 5;
        this->text = text;
        cout << "string parent constructor" << endl;
    }
};

// Don't have to call Parent("hello") due to constructor delegation
class Child: public Parent {
    public:
    Child() : Parent("Hello") {
    }
};

int main() {

    Parent parent("hello");
    Child child;
    return 0;
}