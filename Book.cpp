#include "Book.h"

Book::Book(string id, string t, string a, string p, bool issued)
    : bookID(id), title(t), author(a), publisher(p), isIssued(issued) {}

void Book::setBookDetails(string id, string t, string a, string p, bool issued) {
    bookID = id;
    title = t;
    author = a;
    publisher = p;
    isIssued = issued;
}

void Book::displayBook() const {
    cout << "Book ID: " << bookID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Status: " << (isIssued ? "Issued" : "Available") << endl;
}

string Book::getBookID() const {
    return bookID;
}

bool Book::getStatus() const {
    return isIssued;
}

void Book::issueBook() {
    isIssued = true;
}

void Book::returnBook() {
    isIssued = false;
}

void Book::saveToFile(ofstream &file) const {
    file << bookID << "," << title << "," << author << "," << publisher << "," << isIssued << endl;
}
