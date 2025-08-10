#include "HardcopyBook.h"

/**
 * @brief Constructor for HardcopyBook.
 * It calls the base class (Book) constructor to initialize common properties.
 */
HardcopyBook::HardcopyBook(const std::string& title, const std::string& author, const std::string& isbn, bool available, const std::string& shelfNumber)
    : Book(title, author, isbn, available), shelfNumber(shelfNumber) {
}

/**
 * @brief Overridden function to display details.
 * It first calls the base class function, then adds its own specific details.
 */
void HardcopyBook::displayBookDetails() const {
    Book::displayBookDetails(); // Call the base class version first
    std::cout << "Type: Hardcopy\n"
        << "Shelf Location: " << shelfNumber << "\n"
        << "-------------------------" << std::endl;
}
