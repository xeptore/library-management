#include <string>
#include "book.h"
using namespace std;

Book::Book() {}

Book::~Book() {}

string Book::getAuthor()
{
    return this->author;
}

int Book::getPublishYear()
{
    return this->publishYear;
}

string Book::getName()
{
    return this->name;
}

string Book::getISBN()
{
    return this->isbn;
}

Book *Book::setISBN(string isbn)
{
    this->isbn = isbn;
    return this;
}

Book *Book::setAuthor(string author)
{
    this->author = author;
    return this;
}

Book *Book::setName(string name)
{
    this->name = name;
    return this;
}

Book *Book::setPublishYear(int publishYear)
{
    this->publishYear = publishYear;
    return this;
}
