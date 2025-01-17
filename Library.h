#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "User.h"

class Library {
private:
    vector<Book> books;
    vector<User> users;

    void saveBooks();

public:
    void addBook();
    void displayBooks() const;
    void issueBook();
    void returnBook();
    void addUser();
    void displayUsers() const;
    void saveUsers();
};

#endif
