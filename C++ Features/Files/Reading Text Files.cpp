#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    ifstream inFile;

    //fstream infile;

    string inFileName = "text.txt";

    inFile.open(inFileName);
    //inFile.open(infile, ios::in);
    
    if (inFile.is_open()) {
        string line;
        
        while(inFile) {
            getline(inFile, line);
            cout << line << endl;
        }

        inFile.close();

    }
    else {
        cout << "Cannot open file: " << inFileName << endl;
    }

    return 0;
}