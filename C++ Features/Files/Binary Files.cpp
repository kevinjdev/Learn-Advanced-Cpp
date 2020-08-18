#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1) // gets rid of padding
struct Person {
    // string name; // when writing to a file, don't use string b/c pointers are used
    char name[50];
    int age;
    double height;
};
#pragma pack(pop)

int main() {
    
    Person someone = {"Frodo", 220, 0.8};
    string fileName = "test.bin";

    /////// Write Binary File ////////
    ofstream outputFile;

    outputFile.open(fileName, ios::binary);

    if(outputFile.is_open()) {

        outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

        outputFile.close();
    }
    else {
        cout << "Could not create file " + fileName;
    }
    cout << sizeof(Person) << endl; // 64 bytes with padding. This is a problem for file transfer

    ////// Read Binary File //////
    
    Person someoneElse = {};

    ifstream inputFile;

    inputFile.open(fileName, ios::binary);

    if(inputFile.is_open()) {

        inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));

        inputFile.close();
    }
    else {
        cout << "Could not create file " + fileName;
    }

    cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << endl;
    
    return 0;
}