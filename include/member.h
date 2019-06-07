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
  vector<Book *> borrowedBooks;

public:
  Member(string id);
  ~Member();

  string getFirstName();
  string getLastName();
  uint getEntranceYear();
  string getId();
  vector<Book *> getBorrowedBooks();
  uint getBorrowedBooksCount();
  bool hasBorrowedBook(Book *book);

  Member *setFirstName(string firstName);
  Member *setLastName(string lastName);
  Member *setEntranceYear(uint entranceYear);
  Member *setId(string id);
  uint addBorrowedBook(Book *book);
  bool removeBorrowedBook(Book *book);
};
