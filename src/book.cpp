#include <string>
#include "book.h"
#include "member.h"

using namespace std;


Book::Book()
{
    this->total = 0;
    this->borrowers = vector<Member*>();
}

Book::~Book() {}

string Book::getName()
{
    return this->name;
}

uint Book::getPublishYear()
{
    return this->publishYear;
}

string Book::getAuthor()
{
    return this->author;
}

string Book::getISBN()
{
    return this->isbn;
}

uint Book::getTotal()
{
    return this->total;
}

vector<Member*> Book::getBorrowers()
{
    return this->borrowers;
}

uint Book::getBorrowedCount()
{
    return this->borrowers.size();
}

uint Book::getRemainingCount()
{
    return this->total - this->getBorrowedCount();
}

bool Book::canBeBorrowed()
{
    return this->getRemainingCount() + 1 >= 0;
}

bool Book::canBeBorrowedTo(Member *member)
{
    if (!this->canBeBorrowed())
    {
        return false;
    }

    if (member->hasBorrowedBook(this))
    {
        return false;
    }

    return true;
}


void Book::setName(string name)
{
    this->name = name;
}

void Book::setPublishYear(uint publishYear)
{
    this->publishYear = publishYear;
}

void Book::setISBN(string isbn)
{
    this->isbn = isbn;
}

void Book::setAuthor(string author)
{
    this->author = author;
}

void Book::setTotal(uint total)
{
    this->total = total;
}

void Book::borrowTo(Member *member)
{
    this->borrowers.push_back(member);
    member->addBorrowedBook(this);
}

void Book::unborrowFrom(Member *member)
{
    for (auto m = this->borrowers.begin(); m != this->borrowers.end(); m++)
    {
        if ((*m)->getId() == member->getId())
        {
            this->borrowers.erase(m);
            break;
        }
    }

    member->removeBorrowedBook(this);
}
