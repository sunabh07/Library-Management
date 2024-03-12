#pragma once
#include <stdlib.h>
#include <iostream>
#include "Books.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
using namespace std;
class MyDatabaseConn {
private:
	const string server = "";
	const string username = "";
	const string password = "";
	sql::Connection* con;
public:
	MyDatabaseConn();
	~MyDatabaseConn();
	bool AddQuery(Book b);
	bool FindQuery_name(Book b);
	bool FindQuery_byAuthor(Book b);
	bool FindQuery_byGenre(Book b);
	void UpdateQuery_byName(Book b, string n);
	void UpdateQuery_byAuthor(Book b, string n);
	void UpdateQuery_byGenre(Book b, string n);
	void UpdateQuery_byYear(Book b, int n);
	void DeleteQuery(Book b);
	void ViewAll_fromDatabase();



};
