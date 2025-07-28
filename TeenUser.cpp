#include "TeenUser.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


TeenUser::TeenUser() : User() {
    school = new string("None");
}

TeenUser::TeenUser(string teenName, int teenAge, string* school) : User(teenName, teenAge) {
    school = new string(*school);
}

//setters
void TeenUser::setSchool(string* school) {
    if (school != nullptr) {
        *this->school = *school;
    }
}

//getters
string TeenUser::getSchool() const { return *school; }

void TeenUser::display() const {
    User::display();
    cout << ", School: " << *school << endl;
}

void TeenUser::saveToFile(const string& fileName) const {
    ofstream outFile (fileName, ios::app);
    if (!outFile) {
        cerr << "Could not open file." << endl;
        return;
    }

    outFile << "Name: " << getName() << ", Age: " << getAge() << ", School: " << school << endl;
    outFile.close();
}