#ifndef BOOK_H
#define BOOK_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class User;

class Book {
	static vector<int> price;
	static vector<string> name;
	static vector<int> state;

public:
	static void DisplayBooks();
	static void AddBooks(int p, string n);
	static void DeleteBooks(int position);
	static void BuyBook(User& u);
	static void BookABook(User& u);
};
#endif