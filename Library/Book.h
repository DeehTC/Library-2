#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

// -- Book Base Class Definition --
// This class serves as the base for all types of books in our library.
class Book {
public:
    // Constructor
    Book(const std::string& title, const std::string& author, const std::string& isbn, bool available);

    // Virtual destructor: Essential for proper cleanup when using polymorphism.
    virtual ~Book();

    // virtual displayBookDetails: Allows derived classes to provide their own implementation.
    // 'const' ensures this function doesn't modify the object's state.
    virtual void displayBookDetails() const;

    // --- Common Methods for all book types ---
    bool borrowBook();
    void returnBook();
    std::string getISBN() const;
    bool isAvailable() const;

protected:
    // -- Protected Attributes --
    // Protected so derived classes can access them directly if needed.
    std::string title;
    std::string author;
    std::string isbn;
    bool available; // true for available, false for borrowed
};

#endif // BOOK_H
