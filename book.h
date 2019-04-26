#pragma once
#include <string>

class Book
{
  private:
    std::string name;
    int publishYear;
    std::string author;
    std::string isbn;

  public:
    Book();
    ~Book();

    std::string getAuthor();
    std::string getISBN();
    std::string getName();
    int getPublishYear();

    Book *setISBN(std::string isbn);
    Book *setAuthor(std::string author);
    Book *setName(std::string name);
    Book *setPublishYear(int publishYear);
};