#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string &test) {
    return test.size() == 3;
}

class Check {
    public:
    bool operator()(string &test) {
        return test.size() == 5;
    }
} check1;

// run will accept any function that returns a bool and passes a parameter of type string
void run(function<bool(string&)> check) {
    string test = "stars";
    cout << check(test) << endl;
}

int main() {

    vector<string> vec{"one", "two", "three"};

    int count = count_if(vec.begin(), vec.end(), [](string test){ return test.size() == 3;});

    cout << count << endl;

    int count2 = count_if(vec.begin(), vec.end(), check);

    cout << count2 << endl;

    int count3 = count_if(vec.begin(), vec.end(), check1);

    cout << count3 << endl;

    int size = 5;
    auto lambda = [size](string test) {return test.size() == size;};
    run(lambda); // returns false if not 5 characters
    run(check1);
    run(check);

    function<int(int,int)> add = [](int one, int two){ return one + two; };

    cout << add(7,3) << endl;

    return 0;
}