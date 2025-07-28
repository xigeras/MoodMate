#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

User::User() {
    name = "Unknown";
    age = 0;
}

User::User(string userName, int userAge) {
    name = userName;
    age = userAge;
}

void User::setName(string userName) {
    name = userName;
}

void User::setAge(int userAge) {
    age = userAge;
}

string User::getName() const { return name; }
int User::getAge() const { return age; }

void User::display() const {
    cout << "Name: " << name << ", Age: " << age << endl;
}

void User::saveToFile(const string& fileName) const {
    ofstream outFile(fileName, ios::app);
    if (!outFile) {
        cerr << "Could not open file." << endl;
        return;
    }

    outFile << name << "," << age << endl;
    outFile.close();
}