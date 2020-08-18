#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<string> strings(5);

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");
    strings[3] = "dog";

    for(vector<string>::iterator it = strings.begin(); it != strings.end(); it++)
    {
        cout << *it << endl;
    }

    // it++; // next item

    // cout << *it << endl; // first element
    // for(int i = 0; i < strings.size(); i++)
    // {
    //     cout << strings[i] << endl;
    // }

    

    // cout << strings[3] << endl;

    // cout << strings.size() << endl; // 8

    return 0;
}