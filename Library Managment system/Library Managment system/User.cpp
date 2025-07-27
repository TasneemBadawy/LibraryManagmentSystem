
#include "User.h"
#include <iostream>  // Required for cin and cout

using namespace std;

// Member function definitions
void User::SetName(string name) {
	FullName = name;
}

void User::SetUserId(string id) {
	while (id.length() != 14) {
		cout << "The user ID isn't correct! Enter it again: ";
		cin >> id;
	}
	UserId = id;
}

void User::SetPhoneNumber(string phone) {
	PhoneNumber = phone;
}

void User::SetEmail(string email) {
	Email = email;
}

void User::AddPayment(int price) {
	money += price;
}

int User::GetMoney() {
	return money;
}
