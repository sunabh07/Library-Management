#include <iostream>
#include "Database.h"
#include "Books.h"

void Book:: AddBook() {
	bool status;
	Book b;
	cout << "Enter The Book Name: " << endl;
	cin >> b.bookname;
	cout << "Enter Author Name: " << endl;
	cin >> b.authorname;
	cout << "Enter the Genre of the Book: " << endl;
	cin >> b.genre;
	cout << "Enter the Publication Year of the Book: " << endl;
	cin >> b.publicationyear;

	MyDatabaseConn Mydb;
	status=Mydb.AddQuery(b);
	if (status==0) {
		cout << "Book added successfully.";
	}
	else {
		cout << "Book not added in database.";
	}
	Mydb.~MyDatabaseConn();
};

void Book::FindBook_byname() {
	bool status;
	Book b;
	cout << "Enter Book Name: " << endl;
	cin >> b.bookname;
	MyDatabaseConn Mydb;
	status = Mydb.FindQuery_name(b);
	
	if(status==0) {
		cout << "Try Again !!"<<endl;
	}
	Mydb.~MyDatabaseConn();
}

void Book::FindBook_byAuthor() {
	bool status;
	Book b;
	cout << "Enter Author Name: " << endl;
	cin >> b.authorname;
	MyDatabaseConn Mydb;
	status = Mydb.FindQuery_byAuthor(b);

	if (status == 0) {
		cout << "Book not Found with this Author name." << endl;
	}
	Mydb.~MyDatabaseConn();
}


void Book::FindBook_byGenre() {
	bool status;
	Book b;
	cout << "Enter Genre of the Book: " << endl;
	cin >> b.genre;
	MyDatabaseConn Mydb;
	status = Mydb.FindQuery_byGenre(b);

	if (status == 0) {
		cout << "Book not Found of this Genre ." << endl;
	}
	Mydb.~MyDatabaseConn();
}


void Book::UpdateBook_byName() {
	Book b;
	cout << "Enter the Author Name of the book: " << endl;
	cin >> b.authorname;
	cout << "Enter the Genre of the book: " << endl;
	cin >> b.genre;
	cout << "Enter the Publication year of the book: " << endl;
	cin >> b.publicationyear;

	string n;
	cout << "Enter the new Book name: " << endl;
	cin >> n;
	MyDatabaseConn Mydb;
	Mydb.UpdateQuery_byName(b,n);
	Mydb.~MyDatabaseConn();
};


void Book::UpdateBook_byAuthor() {
	Book b;
	cout << "Enter the  Name of the book: " << endl;
	cin >> b.bookname;
	cout << "Enter the Genre of the book: " << endl;
	cin >> b.genre;
	cout << "Enter the Publication year of the book: " << endl;
	cin >> b.publicationyear;

	string n;
	cout << "Enter the new Author name: " << endl;
	cin >> n;
	MyDatabaseConn Mydb;
	Mydb.UpdateQuery_byAuthor(b, n);
	Mydb.~MyDatabaseConn();
};



void Book::UpdateBook_byGenre() {
	Book b;
	cout << "Enter the  Name of the book: " << endl;
	cin >> b.bookname;
	cout << "Enter the Author of the book: " << endl;
	cin >> b.authorname;
	cout << "Enter the Publication year of the book: " << endl;
	cin >> b.publicationyear;

	string n;
	cout << "Enter the Genre: " << endl;
	cin >> n;
	MyDatabaseConn Mydb;
	Mydb.UpdateQuery_byGenre(b, n);
	Mydb.~MyDatabaseConn();
};



void Book::UpdateBook_byYear() {
	Book b;
	cout << "Enter the  Name of the book: " << endl;
	cin >> b.bookname;
	cout << "Enter the Author of the book: " << endl;
	cin >> b.authorname;
	cout << "Enter the Genre of the book: " << endl;
	cin >> b.genre;

	int n;
	cout << "Enter the Year of Publication: " << endl;
	cin >> n;
	MyDatabaseConn Mydb;
	Mydb.UpdateQuery_byYear(b, n);
	Mydb.~MyDatabaseConn();
};

void Book::DeleteBook() {
	Book b;
	cout << "Enter Book Name you want to delete: " << endl;
	cin >> b.bookname;
	cout << "Enter Author of the book you want to delete: " << endl;
	cin >> b.authorname;
	cout << "Enter the genre of the book you want to delete: " << endl;
	cin >> b.genre;
	cout << "Enter the publication year of the book you want to delete: " << endl;
	cin >> b.publicationyear;
	MyDatabaseConn MyDb;
	MyDb.DeleteQuery(b);
	MyDb.~MyDatabaseConn();

	
}

void Book::ViewAllBook() {
	MyDatabaseConn MyDb;
	MyDb.ViewAll_fromDatabase();
	MyDb.~MyDatabaseConn();
}