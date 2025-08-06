#include "Book.h"
#include "User.h"
// Static variable initialization
vector<int> Book::price{ 219, 319, 319 };
vector<string> Book::name{ "Atomic Habits", "The Art Of Being Alone", "Atop Overthinking" };
vector<int> Book::state{ 0, 0, 2 };

void Book::DisplayBooks() {
	cout << "\n================= Available Books =================\n";
	cout << left << setw(5) << "No."
		<< setw(30) << "Book Name"
		<< setw(15) << "Price"
		<< setw(15) << "Status" << "\n";
	cout << "---------------------------------------------------------------\n";

	for (int i = 0; i < price.size(); i++) {
		cout << left << setw(5) << (i + 1)
			<< setw(30) << name[i]
			<< setw(15) << price[i] << "L.E  "
			<< setw(15) << (state[i] == 0 ? "Not Booked" : (state[i] == 2 ? "Not Available" : "Booked")) << "\n";
	}
	cout << "---------------------------------------------------------------\n";
}

void Book::AddBooks(int p, string n) {
	price.push_back(p);
	name.push_back(n);
	state.push_back(0);
	
}

void Book::DeleteBooks(int position) {
	price.erase(price.begin() + position - 1);
	name.erase(name.begin() + position - 1);
	state.erase(state.begin() + position - 1);
	cout << "Deleted successfully.\n";
}

void Book::BuyBook(User& u) {
	DisplayBooks();
	cout << "Enter the number of the book you want: ";
	int choice;
	cin >> choice;
	choice--;

	if (choice < 0 || choice >= name.size()) {
		cout << "Invalid choice!\n";
		return;
	}

	if (state[choice] == 1) {
		cout << "The book is Booked!\n";
	}
	else if (state[choice] == 2) {
		cout << "The book isn't available!\n";
	}
	else {
		cout << "Purchase successful :)\n";
		state[choice] = 2;
		u.AddPayment(price[choice]);
	}
}

void Book::BookABook(User& u) {
	DisplayBooks();
	cout << "Booking a book requires half the price!\n\n";
	cout << "Enter the number of the book you want: ";
	int choice;
	cin >> choice;
	choice--;

	if (choice < 0 || choice >= name.size()) {
		cout << "Invalid choice!\n";
		return;
	}

	if (state[choice] == 1) {
		cout << "The book is already Booked!\n";
	}
	else if (state[choice] == 2) {
		cout << "The book isn't available!\n";
	}
	else {
		cout << "Booking successful :)\n";
		state[choice] = 1;
		u.AddPayment(price[choice] / 2);
	}
}

