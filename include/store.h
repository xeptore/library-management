#pragma once
#include <string>
#include <vector>

#include "book.h"
#include "member.h"

using namespace std;

class Store
{
  private:
    vector<Book*> books;
    vector<Member*> members;
    vector<Book*> borrowedBooks;

  public:
    Store();
    ~Store();

    Member *findMemberById(string id);
    bool memberExists(string id);
    Book *findBookByISBN(string isbn);
    bool bookExists(string isbn);
    vector<Book*> getBooks();
    vector<Member*> getMembers();

    void addBook(Book *book);
    void addMember(Member *member);
};
