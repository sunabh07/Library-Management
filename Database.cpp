#include "Database.h"
#include "Books.h"
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;



MyDatabaseConn::MyDatabaseConn() {
	sql::Driver* driver;
	driver = get_driver_instance();
	con = driver->connect(server, username, password);
	cout << "Conection created"<<endl;

	con->setSchema("book");
}

MyDatabaseConn::~MyDatabaseConn() {
	delete con;
}
bool MyDatabaseConn::AddQuery(Book b) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("INSERT INTO BOOK_STACK(bookname,authorname,genre,publicationyear) VALUES(?,?,?,?)");
    pstmt->setString(1, b.bookname);
	pstmt->setString(2, b.authorname);
	pstmt->setString(3, b.genre);
	pstmt->setInt(4, b.publicationyear);
	status = pstmt->execute();
	return status;
}

bool MyDatabaseConn::FindQuery_name(Book b) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM BOOK_STACK");
	status = pstmt->execute();
	if (status) {
		sql::ResultSet* res = pstmt->getResultSet();
		if (res) {
			while (res->next())
			{
				string n = res->getString("bookname");
				if (n == b.bookname) {

				string n2 = res->getString("authorname");
				string n3 = res->getString("genre");
				int n4 = res->getInt("publicationyear");
				//cout << "Book name is: " << n << " " << "Author name is: " << n2 << " " << "Genre of the book is: " << n3 << " " << "Publication year of the book is: " << n4 << endl;
				cout << "Book name is: " << n << endl;
				cout << "Author name is: " << n2 << endl;
				cout << "Genre of the book is: " << n3 << endl;
				cout << "Publication Year of the Book is: " << n4 << endl;
				cout << endl;
				cout << endl;

				}
			}
		}
	}
	return status;
}


bool MyDatabaseConn::FindQuery_byAuthor(Book b) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM BOOK_STACK");
	status = pstmt->execute();
	if (status) {
		sql::ResultSet* res = pstmt->getResultSet();
		if (res) {
			while (res->next())
			{
				string n2 = res->getString("authorname");
				if (n2 == b.authorname) {
				string n = res->getString("bookname");

				
					string n3 = res->getString("genre");
					int n4 = res->getInt("publicationyear");
					//cout << "Book name is: " << n << " " << "Author name is: " << n2 << " " << "Genre of the book is: " << n3 << " " << "Publication year of the book is: " << n4 << endl;
					cout << "Book name is: " << n << endl;
					cout << "Author name is: " << n2 << endl;
					cout << "Genre of the book is: " << n3 << endl;
					cout << "Publication Year of the Book is: " << n4 << endl;
					cout << endl;
					cout << endl;
				}
			}
		}
	}
	return status;
}



bool MyDatabaseConn::FindQuery_byGenre(Book b) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM BOOK_STACK");
	status = pstmt->execute();
	if (status) {
		sql::ResultSet* res = pstmt->getResultSet();
		if (res) {
			while (res->next())
			{
					string n3 = res->getString("genre");
				if (n3 == b.genre) {
					string n = res->getString("bookname");
				string n2 = res->getString("authorname");


					int n4 = res->getInt("publicationyear");
					//cout << "Book name is: " << n << " " << "Author name is: " << n2 << " " << "Genre of the book is: " << n3 << " " << "Publication year of the book is: " << n4 << endl;
					cout << "Book name is: " << n << endl;
					cout << "Author name is: " << n2 << endl;
					cout << "Genre of the book is: " << n3 << endl;
					cout << "Publication Year of the Book is: " << n4 << endl;
					cout << endl;
					cout << endl;
				}
			}
		}
	}
	return status;
}


void MyDatabaseConn::UpdateQuery_byName(Book b, string n) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("UPDATE BOOK_STACK  SET bookname=? WHERE authorname=? AND genre=? AND publicationyear=?");
	pstmt->setString(1, n);
	pstmt->setString(2, b.authorname);
	pstmt->setString(3, b.genre);
	pstmt->setInt(4, b.publicationyear);
	status = pstmt->execute();

	if (status==0){
		cout<<"BOOK UPDATE"<<endl;
	}
	else {
		cout << "NOT UPDATED" << endl;
	}

}



void MyDatabaseConn::UpdateQuery_byAuthor(Book b, string n) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("UPDATE BOOK_STACK  SET authorname=? WHERE bookname=? AND genre=? AND publicationyear=?");
	pstmt->setString(1, n);
	pstmt->setString(2, b.bookname);
	pstmt->setString(3, b.genre);
	pstmt->setInt(4, b.publicationyear);
	status = pstmt->execute();

	if (status == 0) {
		cout << "BOOK UPDATE" << endl;
	}
	else {
		cout << "NOT UPDATED" << endl;
	}

}


void MyDatabaseConn::UpdateQuery_byGenre(Book b, string n) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("UPDATE BOOK_STACK  SET genre=? WHERE bookname=? AND authorname=? AND publicationyear=?");
	pstmt->setString(1, n);
	pstmt->setString(2, b.bookname);
	pstmt->setString(3, b.authorname);
	pstmt->setInt(4, b.publicationyear);
	status = pstmt->execute();

	if (status == 0) {
		cout << "BOOK UPDATE" << endl;
	}
	else {
		cout << "NOT UPDATED" << endl;
	}

}



void MyDatabaseConn::UpdateQuery_byYear(Book b, int n) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("UPDATE BOOK_STACK  SET publicationyear=? WHERE bookname=? AND authorname=? AND genre=?");
	pstmt->setInt(1, n);
	pstmt->setString(2, b.bookname);
	pstmt->setString(3, b.authorname);
	pstmt->setString(4, b.genre);
	status = pstmt->execute();

	if (status == 0) {
		cout << "BOOK UPDATE" << endl;
	}
	else {
		cout << "NOT UPDATED" << endl;
	}

}


void MyDatabaseConn::DeleteQuery(Book b) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("DELETE FROM BOOK_STACK WHERE bookname=? AND authorname=? AND genre=? AND publicationyear=?");
	pstmt->setString(1, b.bookname);
	pstmt->setString(2, b.authorname);
	pstmt->setString(3, b.genre);
	pstmt->setInt(4, b.publicationyear);
	status = pstmt->execute();

	if (status == 0) {
		cout << "BOOK DELETED FROM DATABASE" << endl;
	}
	else {
		cout << "BOOK NOT DELETED" << endl;
	}


}

void MyDatabaseConn::ViewAll_fromDatabase() {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM BOOK_STACK");
	status = pstmt->execute();
	if (status) {
		sql::ResultSet* res = pstmt->getResultSet();
		if (res) {
			while (res->next())
			{
				string n = res->getString("bookname");
				string n2 = res->getString("authorname");
				string n3 = res->getString("genre"); 
				int n4 = res->getInt("publicationyear");
				cout << "Book name is: " << n << endl;
				cout << "Author name is: " << n2 << endl;
				cout << "Genre of the book is: " << n3 << endl;
				cout << "Publication Year of the Book is: " << n4 << endl;
				cout << endl;
				cout << endl;


				
			}
		}
	}
}
