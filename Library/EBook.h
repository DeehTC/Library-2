#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h" // Include the base class header

// -- EBook Derived Class --
// Represents a digital book with a license end date.
class EBook : public Book {
public:
    // Constructor: Initializes base class members and its own members.
    EBook(const std::string& title, const std::string& author, const std::string& isbn, bool available, const std::string& licenseEndDate);

    // Override the virtual function from the base class.
    void displayBookDetails() const override;

private:
    std::string licenseEndDate;
};

#endif // EBOOK_H
