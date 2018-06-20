#include "book.h"

void print(pair<string, book> e) {
	cout << e.second;
}

int main() {
	setlocale(LC_ALL, "russian");
	short a;
	cout << "which task?";cin >> a;

	switch (a) {
	case 1: {
		multimap<string, book>bs;
		ifstream inf("book.txt");
		string title, author;

		while (!inf.eof()) {
			inf >> author >> title;
			/*bs.insert(pair<string, book>(author, book(author, title)));*/
		}
		for_each(bs.begin(), bs.end(), print);
	}break;

	case 2:
	{
		multimap<string, book>bs;
		set<string> as;
		ifstream inf("book.txt");
		string title, author;

		while (!inf.eof()) {
			inf >> author >> title;
			/*bs.insert(pair<string, book>(author, book(author, title)));*/
		}

		for (auto it = bs.begin(); it != bs.end();it++) {
			as.insert(it->first);
		}

		for (auto it = as.begin(); it != as.end();it++) {
			auto itr = bs.equal_range(*it);

			cout << *it <<endl;
			for_each(itr.first, itr.second, print);

			cout << endl << endl;
		}


	}break;

	case 3:
	{
		multimap<string, book>bs;
		set<string> as;
		ifstream inf("book.txt");
		string title, author;
		int year, copies;

		while (!inf.eof()) {
			inf >> author >> title >> year >> copies;
			bs.insert(pair<string, book>(author, book(author, title, year, copies)));
		}

		for (auto it = bs.begin(); it != bs.end();it++) {
			as.insert(it->first);
		}

		for (auto it = as.begin(); it != as.end();it++) {
			auto itr = bs.equal_range(*it);

			cout << *it << endl;
			for_each(itr.first, itr.second, print);

			cout << endl << endl;
		}
		do {
			cout << "1 - add" << endl
				<< "2 - delete" << endl
				<< "3 - output by author" << endl
				<< "4 - output by year" << endl
				<< "0 - exit" << endl;
			cin >> a;
			system("cls");
			switch (a) {
			case 1: 
			{
				cout << "введите имя автора: ";cin >> author;
				cout << "введите название книги: ";cin >> title;
				cout << "введите год издания: ";cin >> year;
				cout << "введите тираж: ";cin >> copies;
				bs.insert(pair<string, book>(author, book(author, title, year, copies)));
				for_each(bs.begin(), bs.end(), print);
				cout << endl << endl;
			}break;

			case 2: 
			{
				cout << "введите имя автора, которого вы хотите удалить: "; cin >> author;
				auto itr = bs.find(author);
				if (itr != bs.end())
				{
					bs.erase(itr->first);
				}
				for_each(bs.begin(), bs.end(), print);
				cout << endl << endl;

			}break;

			case 0:
			{
				exit(1);
			}break;

			case 3: {
				cout << "введите имя автора, чтобы увидеть полную информацию: "; cin >> author;
				auto itr = bs.find(author);
				if (itr != bs.end())
				{
					cout << itr->second;
				}
				cout << endl << endl;
			}break;

			case 4: {
				cout << "введите год издания, чтобы увидеть полную информацию: "; cin >> year;
				for (auto it = bs.begin();it != bs.end();it++) {
					if (it->second == year)
						cout << it->second;
				}
			}break;


			}
		} while (a != 0);

		}break;

	}
	system("pause");
	return 0;
	}