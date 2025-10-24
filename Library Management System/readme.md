# 📚 Library Management System (C++)

## Overview

The **Library Management System** is a **console-based application** written in **C++** that allows library administrators and members to manage books efficiently.

It demonstrates **object-oriented programming (OOP) concepts**, **basic system design**, and **data management**. The system supports adding/searching books, issuing and returning books, tracking borrowed books, and calculating fines for late returns.

---

## Features

* ✅ Add new books to the library
* ✅ Add library members
* ✅ Search books by title or author
* ✅ Issue books to members
* ✅ Return books with automatic fine calculation
* ✅ View all books and their current status

**Advanced Extensions (Optional for SDE-2 thinking):**

* Thread-safe operations for concurrency
* Persistent storage (SQLite or JSON file)
* Observer pattern for notifications
* REST API integration using C++ frameworks

---

## Class Structure

| Class         | Responsibilities                                                             |
| ------------- | ---------------------------------------------------------------------------- |
| `Book`        | Represents a book with ID, title, author, category, and status               |
| `Member`      | Represents a library member and tracks borrowed books                        |
| `Transaction` | Handles issuance and return of books, calculates fines                       |
| `Library`     | Core system class: manages books, members, issuing, returning, and searching |

---

## Getting Started

### Prerequisites

* C++ compiler (g++, clang++) supporting C++11 or higher
* Terminal / Command Prompt

### How to Compile

```bash
g++ -std=c++11 main.cpp -o LibrarySystem
```

### How to Run

```bash
./LibrarySystem
```

---

## Example Usage

```
--- Library Books ---
[1] Atomic Habits by James Clear | Category: Self-help | Status: Available
[2] The Alchemist by Paulo Coelho | Category: Fiction | Status: Available

--- Issuing Book ---
Book issued successfully!

--- Books After Issue ---
[1] Atomic Habits by James Clear | Category: Self-help | Status: Issued
[2] The Alchemist by Paulo Coelho | Category: Fiction | Status: Available

--- Returning Book ---
Book returned. Fine: ₹0
```

---

## Code Highlights

* Uses **OOP concepts**: encapsulation, abstraction
* **Fast book lookups** using `unordered_map`
* **Transaction handling** with fine calculation
* Modular and extendable design for future enhancements

---

## Future Improvements

* Implement **thread-safety** with `std::mutex`
* Persist data using **SQLite** or **JSON** files
* Add **GUI or Web Interface**
* Convert into **multi-branch library system**
* Implement **search optimization & indexing**

---

## License

This project is licensed under the **MIT License**.
