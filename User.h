#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
private:
    string userID;
    string name;
    string email;

public:
    User(string id = "", string n = "", string e = "");
    void setUserDetails(string id, string n, string e);
    void displayUser() const;
    string getUserID() const;
    void saveToFile(ofstream &file) const;
};

#endif
