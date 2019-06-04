#include <string>
#include "member.h"
#include "book.h"

using namespace std;

/*
 * Member class constructor
 *
 * @param id student unique identifier.
*/
Member::Member(string id)
{
    this->id = id;
    this->borrowedBooks = vector<Book*>();
}

Member::~Member() {}

string Member::getFirstName()
{
    return this->firstName;
}

string Member::getLastName()
{
    return this->lastName;
}

uint Member::getEntranceYear()
{
    return this->entranceYear;
}

string Member::getId()
{
    return this->id;
}

vector<Book*> Member::getBorrowedBooks()
{
    return this->borrowedBooks;
}

uint Member::getBorrowedBooksCount()
{
    return this->borrowedBooks.size();
}

bool Member::hasBorrowedBook(Book *book)
{
    for (auto b = this->borrowedBooks.begin(); b != this->borrowedBooks.end(); b++)
    {
        if ((*b)->getISBN() == book->getISBN())
        {
            return true;
        }
    }

    return false;
}

void Member::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Member::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Member::setEntranceYear(uint entranceYear)
{
    this->entranceYear = entranceYear;
}

void Member::setId(string id)
{
    this->id = id;
}

uint Member::addBorrowedBook(Book *book)
{
    this->borrowedBooks.push_back(book);
    return this->getBorrowedBooksCount();
}

bool Member::removeBorrowedBook(Book *book)
{
    uint index = 0;
    for (auto b = this->borrowedBooks.begin(); b != this->borrowedBooks.end(); b++)
    {
        if ((*b)->getISBN() == book->getISBN())
        {
            this->borrowedBooks.erase(b);
            return true;
        }
    }

    return false;
}
