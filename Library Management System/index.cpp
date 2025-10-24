#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <iomanip>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    string category;
    bool isIssued;

    Book(int _id, string _title, string _author, string _cat)
        : id(_id), title(_title), author(_author), category(_cat), isIssued(false) {}

    void displayInfo() {
        cout << "[" << id << "] " << title << " by " << author
             << " | Category: " << category
             << " | Status: " << (isIssued ? "Issued" : "Available") << endl;
    }
};

class Member {
public:
    int id;
    string name;
    vector<int> issuedBooks;

    Member(int _id, string _name) : id(_id), name(_name) {}

    void issueBook(int bookId) { issuedBooks.push_back(bookId); }

    void returnBook(int bookId) {
        issuedBooks.erase(remove(issuedBooks.begin(), issuedBooks.end(), bookId), issuedBooks.end());
    }

    void listBorrowed() {
        cout << name << "'s borrowed books: ";
        for (auto b : issuedBooks) cout << b << " ";
        cout << endl;
    }
};

class Transaction {
public:
    int memberId;
    int bookId;
    time_t issueDate;
    time_t dueDate;
    time_t returnDate;
    bool returned;

    Transaction(int mId, int bId) : memberId(mId), bookId(bId), returned(false) {
        issueDate = time(nullptr);
        dueDate = issueDate + (7 * 24 * 60 * 60); // 7 days
    }

    double calculateFine() {
        if (!returned) return 0.0;
        double fine = 0.0;
        if (difftime(returnDate, dueDate) > 0) {
            fine = (difftime(returnDate, dueDate) / (24 * 60 * 60)) * 2.0; // ₹2 per day
        }
        return fine;
    }
};

class Library {
private:
    unordered_map<int, Book> books;
    unordered_map<int, Member> members;
    vector<Transaction> transactions;

public:
    void addBook(Book b) { books[b.id] = b; }

    void addMember(Member m) { members[m.id] = m; }

    void searchBook(string keyword) {
        for (auto &pair : books) {
            if (pair.second.title.find(keyword) != string::npos ||
                pair.second.author.find(keyword) != string::npos)
                pair.second.displayInfo();
        }
    }

    void issueBook(int bookId, int memberId) {
        if (!books.count(bookId) || !members.count(memberId)) {
            cout << "Invalid book or member ID.\n";
            return;
        }
        Book &book = books[bookId];
        if (book.isIssued) {
            cout << "Book already issued.\n";
            return;
        }
        book.isIssued = true;
        members[memberId].issueBook(bookId);
        transactions.emplace_back(memberId, bookId);
        cout << "Book issued successfully!\n";
    }

    void returnBook(int bookId, int memberId) {
        for (auto &t : transactions) {
            if (t.bookId == bookId && t.memberId == memberId && !t.returned) {
                t.returned = true;
                t.returnDate = time(nullptr);
                books[bookId].isIssued = false;
                members[memberId].returnBook(bookId);
                cout << "Book returned. Fine: ₹" << t.calculateFine() << endl;
                return;
            }
        }
        cout << "No active transaction found.\n";
    }

    void displayAllBooks() {
        for (auto &pair : books) pair.second.displayInfo();
    }
};

int main() {
    Library lib;
    lib.addBook(Book(1, "Atomic Habits", "James Clear", "Self-help"));
    lib.addBook(Book(2, "The Alchemist", "Paulo Coelho", "Fiction"));

    lib.addMember(Member(1, "Sultan"));
    lib.addMember(Member(2, "Aisha"));

    cout << "\n--- Library Books ---\n";
    lib.displayAllBooks();

    cout << "\n--- Issuing Book ---\n";
    lib.issueBook(1, 1);

    cout << "\n--- Books After Issue ---\n";
    lib.displayAllBooks();

    cout << "\n--- Returning Book ---\n";
    lib.returnBook(1, 1);

    return 0;
}
