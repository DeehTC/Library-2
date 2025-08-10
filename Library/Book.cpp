#include "Book.h"

// -- Method Implementations for the Book Base Class --

/**
 * @brief Constructor for the Book class.
 */
Book::Book(const std::string& title, const std::string& author, const std::string& isbn, bool available)
    : title(title), author(author), isbn(isbn), available(available) {
}

/**
 * @brief Virtual destructor.
 * Although empty, it's crucial for ensuring derived class destructors are called.
 */
Book::~Book() {}

/**
 * @brief Displays the common details for any book.
 * This base version can be called by derived classes.
 */
void Book::displayBookDetails() const {
    std::cout << "Title: " << title << "\n"
        << "Author: " << author << "\n"
        << "ISBN: " << isbn << "\n"
        << "Status: " << (available ? "Available" : "Borrowed") << std::endl;
}

/**
 * @brief Attempts to borrow the book.
 * @return True if successful, false otherwise.
 */
bool Book::borrowBook() {
    if (available) {
        available = false;
        return true;
    }
    return false;
}

/**
 * @brief Marks the book as returned.
 */
void Book::returnBook() {
    available = true;
}

/**
 * @brief Gets the ISBN of the book.
 * @return The ISBN as a string.
 */
std::string Book::getISBN() const {
    return isbn;
}

/**
 * @brief Checks if the book is available.
 * @return True if available, false otherwise.
 */
bool Book::isAvailable() const {
    return available;
}
