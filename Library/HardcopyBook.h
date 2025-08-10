#ifndef HARDCOPYBOOK_H
#define HARDCOPYBOOK_H

#include "Book.h" // Include the base class header

// -- HardcopyBook Derived Class --
// Represents a physical book with a shelf number.
class HardcopyBook : public Book {
public:
    // Constructor: Initializes base class members and its own members.
    HardcopyBook(const std::string& title, const std::string& author, const std::string& isbn, bool available, const std::string& shelfNumber);

    // Override the virtual function from the base class.
    void displayBookDetails() const override;

private:
    std::string shelfNumber;
};

#endif // HARDCOPYBOOK_H
