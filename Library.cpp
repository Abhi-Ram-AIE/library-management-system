#include "Library.h"
#include <algorithm>

void Library::saveBooks() {
    ofstream file("books.txt");
    if (!file) {
        cout << "Error opening file to save books!\n";
        return;
    }
    for (const auto &book : books) {
        book.saveToFile(file);
    }
    file.close();
    cout << "Books saved automatically.\n";
}

void Library::addBook() {
    string id, title, author, publisher;
    cout << "Enter Book ID: "; cin >> id;
    cout << "Enter Title: "; cin.ignore(); getline(cin, title);
    cout << "Enter Author: "; getline(cin, author);
    cout << "Enter Publisher: "; getline(cin, publisher);

    books.emplace_back(id, title, author, publisher);
    cout << "Book added successfully!\n";
    saveBooks();
}

void Library::displayBooks() const {
    if (books.empty()) {
        cout << "No books available in the library.\n";
        return;
    }
    for (const auto &book : books) {
        book.displayBook();
        cout << "-----------------------\n";
    }
}

void Library::issueBook() {
    string bookID;
    cout << "Enter Book ID to issue: "; cin >> bookID;

    auto it = find_if(books.begin(), books.end(), [&bookID](const Book &b) { return b.getBookID() == bookID && !b.getStatus(); });

    if (it == books.end()) {
        cout << "Book not found or already issued.\n";
        return;
    }

    it->issueBook();
    cout << "Book issued successfully!\n";
    saveBooks();
}

void Library::returnBook() {
    string bookID;
    cout << "Enter Book ID to return: "; cin >> bookID;

    auto it = find_if(books.begin(), books.end(), [&bookID](const Book &b) { return b.getBookID() == bookID && b.getStatus(); });

    if (it == books.end()) {
        cout << "Book not found or not issued.\n";
        return;
    }

    it->returnBook();
    cout << "Book returned successfully!\n";
    saveBooks();
}

void Library::addUser() {
    string id, name, email;
    cout << "Enter User ID: "; cin >> id;
    cout << "Enter Name: "; cin.ignore(); getline(cin, name);
    cout << "Enter Email: "; getline(cin, email);

    users.emplace_back(id, name, email);
    cout << "User added successfully!\n";
}

void Library::displayUsers() const {
    if (users.empty()) {
        cout << "No users registered.\n";
        return;
    }
    for (const auto &user : users) {
        user.displayUser();
        cout << "-----------------------\n";
    }
}

void Library::saveUsers() {
    ofstream file("users.txt");
    if (!file) {
        cout << "Error opening file to save users!\n";
        return;
    }
    for (const auto &user : users) {
        user.saveToFile(file);
    }
    file.close();
    cout << "Users saved to file.\n";
}
