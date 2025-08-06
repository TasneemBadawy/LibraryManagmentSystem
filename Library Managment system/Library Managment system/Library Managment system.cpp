#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>
#include "User.h"
#include "Manager.h"
#include "Book.h"
using namespace std;
const int ManagerDiscount = 100;

// Enable colors in terminal (for older Windows systems)
void EnableColors() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

void LogIn(User& u) {
    string name, id, result, contact;
    cin.ignore();
    cout << "\033[1;34mPlease Enter Your Full Name: \033[0m";
    getline(cin, name);
    u.SetName(name);

    cout << "\033[1;34mPlease Enter your National ID: \033[0m";
    cin >> id;
    u.SetUserId(id);

    cout << "\033[1;34mDo you want to login with Phone or Email: \033[0m";
    cin >> result;

    if (result == "phone" || result == "Phone") {
        cout << "\033[1;34mEnter phone: \033[0m";
        cin >> contact;
        u.SetPhoneNumber(contact);
    }
    else {
        cout << "\033[1;34mEnter email: \033[0m";
        cin >> contact;
        u.SetEmail(contact);
    }
}

void ManagerOptions(Manager& m) {
    int option;
    do {
        cout << "\n\033[1;36m====== Manager Menu ======\033[0m\n";
        cout << "1. Add Books\n2. Delete Books\n3. Buy a Book\n4. Check Total Paid\n0. Exit\n";
        cout << "\033[1;34mChoose: \033[0m";
        cin >> option;

        string name;
        int price;
        switch (option) {
        case 1:
            cout << "\033[1;34mEnter the Book Name & Price:\033[0m ";
            cin.ignore();
            getline(cin, name);
            cin >> price;
            Book::AddBooks(price, name);
            cout << "\033[1;32mBook added successfully!\033[0m\n";
            break;
        case 2:
            Book::DisplayBooks();
            cout << "\033[1;34mEnter the Number of Book: \033[0m";
            int position;
            cin >> position;
            Book::DeleteBooks(position);
            break;
        case 3:
            Book::BuyBook(m);
            break;
        case 4:
            cout << "\033[1;33mYou have paid: " << m.GetMoney() - ManagerDiscount << " L.E\033[0m\n";
            break;
        case 0:
            cout << "\033[1;36mThanks for using our library system!\033[0m\n";
            break;
        default:
            cout << "\033[1;31mInvalid option!\033[0m\n";
        }
    } while (option != 0);
}

void UserOptions(User& u) {
    int option;
    do {
        cout << "\n\033[1;36m====== User Menu ======\033[0m\n";
        cout << "1. Display Books\n2. Book a Book\n3. Buy a Book\n4. Check Total Paid\n0. Exit\n";
        cout << "\033[1;34mChoose: \033[0m";
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
            cout << "\033[1;33mYou have paid: " << u.GetMoney() << " L.E\033[0m\n";
            break;
        case 0:
            cout << "\033[1;35mThanks for using our library system! \033[0m\n";

            break;
        default:
            cout << "\033[1;31mInvalid option!\033[0m\n";
        }
    } while (option != 0);
}

void Draw() {
    cout << "\033[1;36m";
    cout << "\t======================================================\n";
    cout << "\t|                                                     |\n";
    cout << "\t|     -----------------------------------------       |\n";
    cout << "\t|                     WELCOME                         |\n";
    cout << "\t|     -----------------------------------------       |\n";
    cout << "\t|                                                     |\n";
    cout << "\t======================================================\n";
    cout << "\033[0m";
}

int main() {
    EnableColors(); // Ensure color is enabled
    Draw();

    int choice;
    User first;
    Manager m;

    cout << "\n\033[1;34m1 - User Login\n2 - Manager Login\nChoose: \033[0m";
    cin >> choice;
    string id;
    switch (choice) {
    case 1:
        LogIn(first);
        UserOptions(first);
        break;
    case 2:
        LogIn(m);
        cout << "\n\033[1;34mEnter your job ID: \033[0m";
       
        cin >> id;
        m.SetJobId(id);
        ManagerOptions(m);
        break;
    default:
        cout << "\033[1;31mInvalid login choice!\033[0m\n";
    }

    return 0;
}

