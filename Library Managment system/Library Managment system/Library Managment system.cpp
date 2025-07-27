

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "User.h"     // The user class
#include "Manager.h" //  The Manager Class
# include "Book.h"   // The Book Class
using namespace std;
const int ManagerDiscount = 100;

void LogIn(User& u) {
	string name, id, result, contact;
	cin.ignore();
	cout << "\nPlease Enter Your FullName: ";
	getline(cin, name);
	u.SetName(name);

	cout << "\nPlease Enter your National ID: ";
	cin >> id;
	u.SetUserId(id);

	cout << "\nDo you want to login with Phone or Email: ";
	cin >> result;

	if (result == "phone" || result == "Phone") {
		cout << "\nEnter phone: ";
		cin >> contact;
		u.SetPhoneNumber(contact);
	}
	else {
		cout << "\nEnter email: ";
		cin >> contact;
		u.SetEmail(contact);
	}
}
void ManagerOptions(Manager& m) {
	int option;
	do {
		cout << "\n====== User Menu ======\n";
		cout << "1. Add Books\n";
		cout << "2. Delete Books\n";
		cout << "3. Buy a Book\n";
		cout << "4. Check Total Paid\n";
		cout << "0. Exit\n";
		cout << "Choose: ";
		cin >> option;
		string name;
		int price;
		switch (option) {
		case 1:

			cout << "Enter the book Name & Price:";
			cin.ignore();
			getline(cin, name);
			cin >> price;
			Book::AddBooks(price, name);

			break;
		case 2:
			Book::DisplayBooks();
			cout << "Enter the Number of Book :";
			int position;
			cin >> position;
			Book::DeleteBooks(position);
			break;
		case 3:
			Book::BuyBook(m);
			break;
		case 4:
			cout << "You have paid: " << m.GetMoney() - ManagerDiscount << " L.E\n";
			break;
		case 0:
			cout << "Thanks for using our library system!\n";
			break;
		default:
			cout << "Invalid option!\n";
		}

	} while (option != 0);
}
void UserOptions(User& u) {
	int option;
	do {
		cout << "\n====== User Menu ======\n";
		cout << "1. Display Books\n";
		cout << "2. Book a Book\n";
		cout << "3. Buy a Book\n";
		cout << "4. Check Total Paid\n";
		cout << "0. Exit\n";
		cout << "Choose: ";
		cin >> option;

		switch (option) {
		case 1:
			Book::DisplayBooks();
			break;
		case 2:
			Book::BookABook(u);
			break;
		case 3:
			Book::BuyBook(u);
			break;
		case 4:
			
			cout << "You have paid: " << u.GetMoney() << " L.E\n";
			break;
		case 0:
			cout << "Thanks for using our library system!\n";
			break;
		default:
			cout << "Invalid option!\n";
		}

	} while (option != 0);
 }

void Draw() {
	cout << "\t======================================================\n";
	cout << "\t|                                                     |\n";
	cout << "\t|     -----------------------------------------       |\n";
	cout << "\t|                     WELCOME                         |\n";
	cout << "\t|     -----------------------------------------       |\n";
	cout << "\t|                                                     |\n";
	cout << "\t======================================================\n";
}

int main()
{
	Draw();
	int choice;
	User first;
	Manager m;
	cout << "1-User Login. \n2-Manager Login. \n";
	cout << "Choose:";
	cin >> choice;
	switch (choice) {
	case 1:
		LogIn(first);
		UserOptions(first);
		break;
	case 2:
		LogIn(m);
		cout << "\nEnter your job ID: ";
		string id;
		cin >> id;
		m.SetJobId(id);
		ManagerOptions(m);
		break;
	}
}

