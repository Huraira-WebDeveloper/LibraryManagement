#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class with basic properties
class Book {
public:
    string title;
    string author;
    string isbn;
    bool isAvailable;

    // Constructor
    Book(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        isAvailable = true;
    }

    void display() {
        cout << "\nBook: " << title
             << "\nAuthor: " << author
             << "\nISBN: " << isbn
             << "\nStatus: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};

// Library management system
class Library {
private:
    vector<Book> books;

public:
    // Add a new book to the library
    void addBook() {
        string title, author, isbn;
        
        cout << "\nEnter book title: ";
        getline(cin, title);
        
        cout << "Enter author name: ";
        getline(cin, author);
        
        cout << "Enter ISBN: ";
        getline(cin, isbn);

        // Check if ISBN already exists
        bool exists = false;
        for(Book& book : books) {
            if(book.isbn == isbn) {
                exists = true;
                break;
            }
        }

        if(!exists) {
            books.push_back(Book(title, author, isbn));
            cout << "Book added successfully!\n";
        } else {
            cout << "Book with this ISBN already exists!\n";
        }
    }

    // Display all books
    void showAllBooks() {
        if(books.empty()) {
            cout << "\nNo books in the library!\n";
            return;
        }

        cout << "\n=== Library Books ===\n";
        for(Book& book : books) {
            book.display();
        }
    }

    // Borrow a book
    void borrowBook() {
        string isbn;
        cout << "\nEnter ISBN of book to borrow: ";
        getline(cin, isbn);

        for(Book& book : books) {
            if(book.isbn == isbn) {
                if(book.isAvailable) {
                    book.isAvailable = false;
                    cout << "Book borrowed successfully!\n";
                } else {
                    cout << "Book is already borrowed!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Return a book
    void returnBook() {
        string isbn;
        cout << "\nEnter ISBN of book to return: ";
        getline(cin, isbn);

        for(Book& book : books) {
            if(book.isbn == isbn) {
                if(!book.isAvailable) {
                    book.isAvailable = true;
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "Book was not borrowed!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }
};

// Main menu
int main() {
    Library library;
    int choice;

    do {
        cout << "\n=== Library System ===\n"
             << "1. Add Book\n"
             << "2. Show All Books\n"
             << "3. Borrow Book\n"
             << "4. Return Book\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch(choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.showAllBooks();
                break;
            case 3:
                library.borrowBook();
                break;
            case 4:
                library.returnBook();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while(choice != 5);

    return 0;
}