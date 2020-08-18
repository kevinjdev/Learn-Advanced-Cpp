#include <iostream>
#include <vector>
using namespace std;

struct S1 {
    string text;
    int id;
};

int main() {

    int values[] = {4,5,6,7,8};
    cout << values[0] << endl;

    S1 s = {"heello", 7};

    cout << s.text << endl;

    vector<string> strings;
    strings.push_back("One");
    strings.push_back("Two");
    strings.push_back("Three");
    return 0;
}