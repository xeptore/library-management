#pragma once
#include <string>
#include <vector>

using namespace std;

class Member;

class Book
{
private:
  string name;
  uint publishYear;
  string author;
  string isbn;
  uint total;
  vector<Member *> borrowers;

public:
  Book();
  ~Book();

  string getName();
  uint getPublishYear();
  string getAuthor();
  string getISBN();
  uint getTotal();
  vector<Member *> getBorrowers();
  uint getBorrowedCount();
  uint getRemainingCount();
  bool canBeBorrowed();
  bool canBeBorrowedTo(Member *member);

  Book *setName(string name);
  Book *setPublishYear(uint publishYear);
  Book *setISBN(string isbn);
  Book *setAuthor(string author);
  Book *setTotal(uint total);
  void borrowTo(Member *member);
  void takeBackFrom(Member *member);
};
