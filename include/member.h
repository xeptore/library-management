#pragma once
#include <string>
#include <vector>

using namespace std;

class Book;

class Member
{
  private:
    string firstName;
    string lastName;
    uint entranceYear;
    string id;
    vector<Book*> borrowedBooks;

  public:
    Member(string id);
    ~Member();

    string getFirstName();
    string getLastName();
    uint getEntranceYear();
    string getId();
    vector<Book*> getBorrowedBooks();
    uint getBorrowedBooksCount();
    bool hasBorrowedBook(Book *book);

    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEntranceYear(uint entranceYear);
    void setId(string id);
    uint addBorrowedBook(Book *book);
    bool removeBorrowedBook(Book *book);
};
