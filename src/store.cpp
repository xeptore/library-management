#include<vector>
#include<algorithm>

#include "book.h"
#include "member.h"
#include "store.h"

using namespace std;


Store::Store()
{
    this->members = vector<Member*>();
    this->books = vector<Book*>();
}

Store::~Store() {}

Member *Store::findMemberById(string id)
{
    for (auto m = this->members.begin(); m != this->members.end(); m++)
    {
        if ((*m)->getId() == id)
        {
            auto index = distance(this->members.begin(), m);
            return this->members.at(index);
        }
    }

    return NULL;
}

bool Store::memberExists(string id)
{
    for (auto m = this->members.begin(); m != this->members.end(); m++)
    {
        if ((*m)->getId() == id)
        {
            return true;
        }
    }

    return false;
}

Book *Store::findBookByISBN(string isbn)
{
    for (auto b = this->books.begin(); b != this->books.end(); b++)
    {
        if ((*b)->getISBN() == isbn)
        {
            auto index = distance(this->books.begin(), b);
            return this->books.at(index);
        }
    }

    return NULL;
}

bool Store::bookExists(string isbn)
{
    for (auto b = this->books.begin(); b != this->books.end(); b++)
    {
        if ((*b)->getISBN() == isbn)
        {
            return true;
        }
    }

    return false;
}

vector<Member*> Store::getMembers()
{
    return this->members;
}

vector<Book*> Store::getBooks()
{
    return this->books;
}

void Store::addBook(Book *book)
{
    this->books.push_back(book);
}

void Store::addMember(Member *member)
{
    this->members.push_back(member);
}

