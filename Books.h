#pragma once
#include <iostream>
using namespace std;

class Book {
public:
	string bookname;
	string authorname;
	string genre;
	int publicationyear;
	

public:
	void AddBook();
	void FindBook_byname();
	void FindBook_byAuthor();
	void FindBook_byGenre();
	void UpdateBook_byName();
	void UpdateBook_byAuthor();
	void UpdateBook_byGenre();
	void UpdateBook_byYear();
	void DeleteBook();
	void ViewAllBook();

};
