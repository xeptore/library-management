#include <iostream>

#include "book.h"
#include "member.h"
#include "store.h"

using namespace std;

int main() {
    
    auto store = Store();

    auto member = Member("df5gdg8+");
    member.setFirstName("taqi");
    member.setLastName("safari");
    member.setEntranceYear(1567);
    store.addMember(&member);

    auto book = new Book();
    book->setAuthor("json");
    book->setISBN("46743543");
    book->setName("kiri dar faza");
    book->setPublishYear(1998);
    book->setTotal(20);

    store.addBook(book);

    book = new Book();
    book->setAuthor("jacob");
    book->setISBN("46743421");
    book->setName("ketabi khoob");
    book->setPublishYear(1995);
    book->setTotal(50);

    store.addBook(book);

    auto storemembers = store.getMembers();
    for (auto i = storemembers.begin(); i != storemembers.end(); i++)
    {
        auto item = (*i);
        cout << item->getId() << " - " << item->getEntranceYear() << " - " << item->getFirstName() << " - " << item->getLastName() << endl;
    }

    auto storeBooks = store.getBooks();
    for (auto i = storeBooks.begin(); i != storeBooks.end(); i++)
    {
        auto item = (*i);
        cout << item->getAuthor() << " - " << item->getBorrowedCount() << " - " << item->getISBN() << " - " << item->getName() << " - " << item->getPublishYear() << " - " << item->getRemainingCount() << " - " << item->getTotal() << endl;
    }

    cout << endl << endl << endl;

    auto foundBook = store.findBookByISBN("46743543");
    if (foundBook != NULL)
    {
        cout << foundBook->getAuthor() << " - " << foundBook->getBorrowedCount() << " - " << foundBook->getISBN() << " - " << foundBook->getName() << " - " << foundBook->getPublishYear() << " - " << foundBook->getRemainingCount() << " - " << foundBook->getTotal() << endl;
    }

    return 0;
}
