#include "EBook.h"

/**
 * @brief Constructor for EBook.
 * It calls the base class (Book) constructor to initialize common properties.
 */
EBook::EBook(const std::string& title, const std::string& author, const std::string& isbn, bool available, const std::string& licenseEndDate)
    : Book(title, author, isbn, available), licenseEndDate(licenseEndDate) {
}

/**
 * @brief Overridden function to display details.
 * It first calls the base class function, then adds its own specific details.
 */
void EBook::displayBookDetails() const {
    Book::displayBookDetails(); // Call the base class version first
    std::cout << "Type: E-Book\n"
        << "License Expires: " << licenseEndDate << "\n"
        << "-------------------------" << std::endl;
}
