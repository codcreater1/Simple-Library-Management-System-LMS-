#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Book {
	int id;
	string title;
	string author;
	bool isBorrowed;
		
};


void addBook(vector<Book>& books, int& nextId) {
	Book newBook;

	cout << "Please enter the TITLE: " << endl;
	getline(cin >> ws, newBook.title);

	cout << "Enter AUTHOR name: ";
	getline(cin >> ws, newBook.author);

	newBook.id = nextId;
	newBook.isBorrowed = false;

	books.push_back(newBook);
	cout << "Book added successfully! ID: " << newBook.id << endl;

	nextId++;
}


void deleteBook(vector<Book>& books) {
	int id;
	cout << "Please enter ID to delete the book: " << endl;
	cin >> id;

	bool found = false;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].id == id) {
			books.erase(books.begin() + i);
			cout << "BOOK DELETED SUCCESSFULLY." << endl;
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "Book couldn't found." << endl;
	}
}

void borrowBook(vector<Book>& books) {
	if (books.empty()) {
		cout << "book couldnt find" << endl;
		return;
	}
	cout << "LIST OF BOOKS" << endl;
	for (const Book& book : books) {
		if (!book.isBorrowed) {
		
			cout << "ID: " << book.id << " | Title: " << book.title << endl;
		}
		
	}
	cout << "Enter ID of the book to borrow: ";
	int id;
	cin >> id;

	bool found = false;
	for (Book& book : books) {
		if (book.id == id && !book.isBorrowed) {
			book.isBorrowed = true;
			cout << "Book borrowed succesfully" << endl;
			found = true;
			break;
		
		}
	
	}
	if (!found) {
		cout << "Book not found or already borrowed." << endl;
	}


}
void viewBooks(vector<Book>& books) {
	

	
	if (books.empty()) {
		cout << "book couldnt find" << endl;
		return;
	}
	cout << "--- ALL BOOKS---" << endl;

	for (const Book& book : books) {
		 {
			cout << "ID: " << book.id << endl;
			cout << "Title: " << book.title << endl;
			cout << "Author: " << book.author << endl;
			cout << "Borrowed: " << (book.isBorrowed ? "Yes" : "No") << endl;
			cout << "--------------------------" << endl;
		
		}
		

	
	}

}

void returnBook(vector<Book>& books) {
	if (books.empty()) {
		cout << "There are no books in the library." << endl;
		return;
	}

	cout << "BOOKS AVAILABLE TO RETURN:" << endl;
	bool anyBorrowed = false;
	for (const Book& book : books) {
		if (book.isBorrowed) {
			cout << "ID: " << book.id << " | Title: " << book.title << endl;
			anyBorrowed = true;
		}
	}

	if (!anyBorrowed) {
		cout << "No books to return." << endl;
		return;
	}

	int id;
	cout << "Enter the ID of the book you want to return: ";
	cin >> id;

	bool found = false;
	for (Book& book : books) {
		if (book.id == id && book.isBorrowed) {
			book.isBorrowed = false;
			cout << "Book returned successfully!" << endl;
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "Book not found or already returned." << endl;
	}
}


int main() {
	Book myBook;
	vector<Book> books;
	int nextId = 1;
	char choice;

	cout << "WELCOME TO MY 'LMS'" << endl;
	cout << "--------------------" << endl;

	
	do
	{
		cout << "LMS MENU" << endl;
		cout << "1. ADD BOOK" << endl;
		cout << "2.DELETE BOOK" << endl;
		cout << "3.VIEW ALL BOOKS" << endl;
		cout << "4.BORROW BOOK" << endl;
		cout << "5.RETURN BOOK" << endl;
		cout << "6.EXIT" << endl;

		cout << "PLEASE ENTER YOUR CHOICE BETWEEN(1-6)" << endl;
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case '1':
			addBook(books, nextId);
			break;
		case '2':
			deleteBook(books);
			break;
		case'3':
			viewBooks(books);
			break;
		case '4':
			borrowBook(books);
			break;
		case '5':
			returnBook(books);
			break;
		case'6':
			cout << "GOOD BYE" << endl;
			break;
		default:
			cout << "WRONG NUMBER,PLEASE ENTER NUMBERS BETWEEN(1-6)";


		}

	} while (choice !='6');


	

	return 0;
}
