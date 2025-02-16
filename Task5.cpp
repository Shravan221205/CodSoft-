#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool isCheckedOut;
    time_t dueDate;
};

struct Borrower {
    string name;
    vector<string> borrowedBooks;
};

vector<Book> books;
vector<Borrower> borrowers;

const int loanPeriod = 14; // Loan period in days
const double finePerDay = 0.5; // Fine per day for overdue books

void addBook() {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter book author: ";
    getline(cin, newBook.author);
    cout << "Enter book ISBN: ";
    getline(cin, newBook.isbn);
    newBook.isCheckedOut = false;
    newBook.dueDate = 0;
    books.push_back(newBook);
    cout << "Book added.\n";
}

void searchBooks() {
    string query;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, query);
    for (const auto& book : books) {
        if (book.title.find(query) != string::npos ||
            book.author.find(query) != string::npos ||
            book.isbn.find(query) != string::npos) {
            cout << "Title: " << book.title << ", Author: " << book.author
                 << ", ISBN: " << book.isbn << ", " 
                 << (book.isCheckedOut ? "Checked Out" : "Available") << endl;
        }
    }
}

void checkoutBook() {
    string borrowerName, isbn;
    cout << "Enter borrower's name: ";
    cin.ignore();
    getline(cin, borrowerName);
    cout << "Enter book ISBN to checkout: ";
    getline(cin, isbn);
    for (auto& book : books) {
        if (book.isbn == isbn && !book.isCheckedOut) {
            book.isCheckedOut = true;
            time_t now = time(0);
            book.dueDate = now + loanPeriod * 24 * 60 * 60;
            for (auto& borrower : borrowers) {
                if (borrower.name == borrowerName) {
                    borrower.borrowedBooks.push_back(isbn);
                    cout << "Book checked out to " << borrowerName << ".\n";
                    return;
                }
            }
            Borrower newBorrower;
            newBorrower.name = borrowerName;
            newBorrower.borrowedBooks.push_back(isbn);
            borrowers.push_back(newBorrower);
            cout << "Book checked out to " << borrowerName << ".\n";
            return;
        }
    }
    cout << "Book not available or invalid ISBN.\n";
}

void returnBook() {
    string borrowerName, isbn;
    cout << "Enter borrower's name: ";
    cin.ignore();
    getline(cin, borrowerName);
    cout << "Enter book ISBN to return: ";
    getline(cin, isbn);
    for (auto& borrower : borrowers) {
        if (borrower.name == borrowerName) {
            auto it = find(borrower.borrowedBooks.begin(), borrower.borrowedBooks.end(), isbn);
            if (it != borrower.borrowedBooks.end()) {
                borrower.borrowedBooks.erase(it);
                for (auto& book : books) {
                    if (book.isbn == isbn) {
                        book.isCheckedOut = false;
                        time_t now = time(0);
                        double fine = difftime(now, book.dueDate) / (24 * 60 * 60) * finePerDay;
                        if (fine > 0) {
                            cout << "Book is overdue. Fine: $" << fine << endl;
                        }
                        cout << "Book returned.\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "Invalid borrower name or ISBN.\n";
}

void showMenu() {
    cout << "Library Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Search Books\n";
    cout << "3. Checkout Book\n";
    cout << "4. Return Book\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    while (true) {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBooks();
                break;
            case 3:
                checkoutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
