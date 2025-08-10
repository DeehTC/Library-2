#include <iostream>
#include <string>
#include <limits>
#include "EBook.cpp"
#include "HardcopyBook.cpp" 
#include "HardcopyBook.h" // Include derived class headers
#include "EBook.h"

// The total number of books our library will hold.
const int LIBRARY_SIZE = 5;

// Function prototypes
void displayMenu();
// The 'const' is removed from the first parameter to match the argument type in main()
void seeAllBooks(Book* library[], int size);
void borrowBook(Book* library[], int size);
void returnBook(Book* library[], int size);

int main() {
    // -- Polymorphic Array --
    // Create an array of base class POINTERS.
    // This allows us to store addresses of different derived class objects.
    Book* library[LIBRARY_SIZE];

    // -- Initialization with dynamic allocation ('new') --
    library[0] = new HardcopyBook("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "9780345391803", true, "Sci-Fi A-10");
    library[1] = new EBook("The Lord of the Rings", "J.R.R. Tolkien", "9780618640157", true, "2025-12-31");
    library[2] = new HardcopyBook("To Kill a Mockingbird", "Harper Lee", "9780061120084", false, "Classics C-5"); // Borrowed
    library[3] = new EBook("1984", "George Orwell", "9780451524935", true, "2026-06-15");
    library[4] = new HardcopyBook("Pride and Prejudice", "Jane Austen", "9780141439518", true, "Classics A-2");

    int choice = 0;

    while (choice != 4) {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "\nInvalid input. Please enter a number between 1 and 4.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
        case 1:
            seeAllBooks(library, LIBRARY_SIZE);
            break;
        case 2:
            borrowBook(library, LIBRARY_SIZE);
            break;
        case 3:
            returnBook(library, LIBRARY_SIZE);
            break;
        case 4:
            std::cout << "\nThank you for visiting the library. Goodbye!\n";
            break;
        default:
            std::cout << "\nInvalid option. Please choose a number between 1 and 4.\n";
            break;
        }
    }

    // -- Memory Cleanup --
    // Crucial: Delete all objects created with 'new' to prevent memory leaks.
    for (int i = 0; i < LIBRARY_SIZE; ++i) {
        delete library[i];
        library[i] = nullptr; // Good practice to null the pointer after deleting.
    }

    return 0;
}

/**
 * @brief Displays the main menu options to the user.
 */
void displayMenu() {
    std::cout << "\n===== Library Menu =====\n"
        << "1. See all books\n"
        << "2. Borrow a book\n"
        << "3. Return a book\n"
        << "4. Leave\n"
        << "========================\n"
        << "Enter your choice: ";
}

/**
 * @brief Displays all books in the library.
 * Thanks to polymorphism, calling displayBookDetails() executes the correct
 * version (for HardcopyBook or EBook) automatically.
 */
void seeAllBooks(Book* library[], int size) {
    std::cout << "\n===== Full Library Inventory =====\n" << std::endl;
    for (int i = 0; i < size; ++i) {
        // Use the arrow operator (->) for pointers
        library[i]->displayBookDetails();
    }
}

/**
 * @brief Handles borrowing a book.
 */
void borrowBook(Book* library[], int size) {
    std::string isbn;
    std::cout << "\nEnter the ISBN of the book you wish to borrow: ";
    std::cin >> isbn;

    bool bookFound = false;
    for (int i = 0; i < size; ++i) {
        if (library[i]->getISBN() == isbn) {
            bookFound = true;
            if (library[i]->borrowBook()) {
                std::cout << "\nSUCCESS: You have borrowed the book.\n";
            }
            else {
                std::cout << "\nERROR: This book is already borrowed.\n";
            }
            break;
        }
    }

    if (!bookFound) {
        std::cout << "\nERROR: No book with the ISBN '" << isbn << "' was found.\n";
    }
}

/**
 * @brief Handles returning a book.
 */
void returnBook(Book* library[], int size) {
    std::string isbn;
    std::cout << "\nEnter the ISBN of the book you wish to return: ";
    std::cin >> isbn;

    bool bookFound = false;
    for (int i = 0; i < size; ++i) {
        if (library[i]->getISBN() == isbn) {
            bookFound = true;
            if (!library[i]->isAvailable()) {
                library[i]->returnBook();
                std::cout << "\nSUCCESS: Thank you for returning the book.\n";
            }
            else {
                std::cout << "\nINFO: This book was already marked as available.\n";
            }
            break;
        }
    }

    if (!bookFound) {
        std::cout << "\nERROR: No book with the ISBN '" << isbn << "' was found.\n";
    }
}
