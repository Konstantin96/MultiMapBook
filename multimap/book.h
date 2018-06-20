#pragma once
#include "Headers.h"

class book {
private:
	string author;
	string title;
	int year;
	int numOfCopies;
public:
	book() {
		this->author = "";
		this->title = "";
		this->year = 0;
		this->numOfCopies = 0;
	}
	book(string name, string bookname, int year, int count) {
		this->author = name;
		this->title = bookname;
		this->year = year;
		this->numOfCopies = count;

	}

	friend ostream& operator<<(ostream &os, book b) {
		os << b.author << "\t" << b.title << "\t" << b.year <<"\t"<<b.numOfCopies<< endl;
		return os;
	}

	bool operator ==(size_t year) {
		return(this->year == year);
	}
};
