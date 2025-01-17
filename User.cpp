#include "User.h"

User::User(string id, string n, string e) : userID(id), name(n), email(e) {}

void User::setUserDetails(string id, string n, string e) {
    userID = id;
    name = n;
    email = e;
}

void User::displayUser() const {
    cout << "User ID: " << userID << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
}

string User::getUserID() const {
    return userID;
}

void User::saveToFile(ofstream &file) const {
    file << userID << "," << name << "," << email << endl;
}
