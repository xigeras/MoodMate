#ifndef TEENUSER_H
#define TEENUSER_H

#include "User.h"

Class TeenUser : public User {
    private: 
        string schoolName;
    public:
        TeenUser();
        TeenUser(string teenName, int teenAge, string school);

        void setSchool(string* school);

        string getSchool() const;

        void display() const override;
        void saveToFile(const string& fileName) const override;
};
#endif