#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
    private:
        string name;
        int age;

    public:
        User();
        User(string userName, int userAge);

        //setters
        void setName(string userName);
        void setAge(int& userAge);

        //getters
        string getName() const;
        int getAge() const;

        virtual void display() const;

        virtual void saveToFile(const string& fileName) const;
};

#endif
