# 📚 Library Management System

A C++ console-based application for managing a small library. This project demonstrates core Object-Oriented Programming (OOP) principles including encapsulation, inheritance, static members.

---

## 🚀 Features

* 📖 View available books
* ➕ Add books (Manager only)
* ❌ Delete books (Manager only)
* 💸 Buy books (User)
* 📘 Book a book (User)
* 🧾 Track total payments per user

---

## 🧱 Technologies Used

* **Language:** C++
* **Paradigm:** Object-Oriented Programming
* **Compiler:** MSVC (Visual Studio) / g++

---

## 🏗️ Project Structure

```
LibraryManagementSystem/
├── Book.cpp / Book.h         # Book class - static management of book list
├── User.cpp / User.h         # User class - stores personal info and payments
├── Manager.cpp / Manager.h   # Manager class - inherits from User
├── Library Management system.cpp  # Main program logic and user interaction
├── Library Management system.sln  # Visual Studio solution file
```

---

## 🧑‍💻 OOP Concepts Implemented

| Concept        | Implementation                                              |
| -------------- | ----------------------------------------------------------- |
| Encapsulation  | All classes keep attributes private                         |
| Inheritance    | `Manager` inherits from `User`                              |
| Static Members | Book data is shared across all instances                    |

---

## 🧪 How to Run

### ✅ Using Visual Studio:

1. Open `.sln` file.
2. Build Solution (Ctrl + Shift + B)
3. Run (F5)

### ✅ Using g++ (CLI):

```bash
g++ -std=c++11 Book.cpp User.cpp Manager.cpp "Library Management system.cpp" -o LibraryApp
./LibraryApp
```

📄 License

This project is for educational use only. No license required.


