#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book {
private:
    string bookID;
    string title;
    string author;
    string publisher;
    bool isIssued;

public:
    Book(string id = "", string t = "", string a = "", string p = "", bool issued = false);
    void setBookDetails(string id, string t, string a, string p, bool issued = false);
    void displayBook() const;
    string getBookID() const;
    bool getStatus() const;
    void issueBook();
    void returnBook();
    void saveToFile(ofstream &file) const;
};

#endif
