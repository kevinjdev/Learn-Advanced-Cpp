#include <iostream>
#include <list>
using namespace std;

// In a list you can insert items in the beginning or middle instead of the end. This is a doubly linked list

int main() {
    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);

    list<int>::iterator it2 = numbers.begin();
    it2++;
    numbers.insert(it2, 100);
        
    for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
    list<int>::iterator it3 = numbers.begin();
    it3++;
    cout << "Element" << *it3 << endl;
    it3 = numbers.erase(it3); //assigns iterator to element after element erased
    // cout << *it2 << endl;

    for(list<int>::iterator it = numbers.begin(); it != numbers.end();) {
        if(*it == 2) {
            numbers.insert(it, 1234);
        }

        if(*it == 1) {
            it = numbers.erase(it); // this will move iterator forward
        }
        else {
            it++;
        }
    }

    for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
}