#include<iostream>
#include<map>

using namespace std;

int main() {

    map<string, int> ages;
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicki"] = 30;

    ages["Mike"] = 70; // overwrites 40

    // using a pair
    pair<string, int> addToMap("Peter", 100);
    ages.insert(addToMap);

    //or 
    ages.insert(pair<string, int>("Willy", 20));

    //or
    ages.insert(make_pair("Dan", 50));

    cout << ages["Rag"] << endl; // attempting to access an key not in a map will add it with a value of 0

    if(ages.find("Vicki") != ages.end()) {
        cout << "Found Vicki" << endl;
    }
    else {
        cout << "Key not found " << endl;
    }

    for(map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        pair<string, int> age = *it;

        cout << age.first << ": " << age.second << endl;
    }

    for(map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}