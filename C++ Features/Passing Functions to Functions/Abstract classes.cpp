#include <iostream>
using namespace std;

class Animal {
    public:
    virtual void run() = 0;
    virtual void speak() = 0; // pure virtual function
};

// must implment all virtual functions
class Dog: public Animal {
    public:
    virtual void speak() {
        cout << "Woof!" << endl;
    }
};

class Labrador: public Dog {
    public:
    Labrador() {
        cout << "New labrador" << endl;
    }
    virtual void run() {
        cout << "labrador running" << endl;
    }
};

int main() {

    //Dog dog;
    //dog.speak();

    Labrador lab;
    lab.run();
    lab.speak();

    // cannot create an array of animals b/c you can't run a constructor for Animal but can do a pointer
    Animal *animals[5];
    animals[0] = &lab;

    animals[0]->speak();

    return 0;
}