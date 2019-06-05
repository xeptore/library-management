#include <iostream>
#include <limits>

#include "book.h"
#include "member.h"
#include "store.h"
#include "util.h"

using namespace std;

void banner();
void help();
int getaction();

void addNewMember(Store *store);
void addNewBook(Store *store);
void borrowBookToMember(Store *store);
void takeBackBookFromMember(Store *store);
void listMemberBorrowedBooks(Store *store);

int main()
{
    auto store = new Store();

    banner();

    while (true)
    {
        help();
        int action = 0;
        while ((action = getaction()) == -1)
        {
            error("Invalid input.");
            error("Just enter number of the option you want.");
            help();
        }

        println();

        switch (action)
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            addNewMember(store);
            break;
        }
        case 2:
        {
            addNewBook(store);
            break;
        }
        case 3:
        {
            borrowBookToMember(store);
            break;
        }
        case 4:
        {
            takeBackBookFromMember(store);
            break;
        }
        case 5:
        {
            listMemberBorrowedBooks(store);
            break;
        }
        default:
            break;
        }
    }

    return 0;
}

void banner()
{
    cout << endl;
    println("******************************************");
    println("*                                        *");
    println("*         Library Management App         *");
    println("*                                        *");
    println("******************************************");
    cout << endl;
}

void help()
{
    cout << endl;
    println("Choose one the following options:");
    println("[ " + yellow("1") + " ] " + "Add a new member");
    println("[ " + yellow("2") + " ] " + "Add a new book to library");
    println("[ " + yellow("3") + " ] " + "Borrow a book to a member");
    println("[ " + yellow("4") + " ] " + "Take-back a book from a member");
    println("[ " + yellow("5") + " ] " + "Show a list of borrowed books from a member");
    println("[ " + yellow("6") + " ] " + "Show a list of books in the library");
    println("[ " + yellow("7") + " ] " + "Show a list of books in the library");
    println("[ " + grey("0") + " ] " + "Exit");
    cout << endl;
}

int getaction()
{
    auto action = promptInt("What can i do for you:");
    if (cin.fail() || action > 7 || action < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return action;
}

void addNewMember(Store *store)
{
    string firstName, lastName, id;
    uint entranceYear;

    info("Enter new member information:");

    firstName = promptString("First Name:");
    lastName = promptString("Last Name:");
    id = promptString("Student ID:");
    entranceYear = (uint)promptInt("Entrance Year:");

    auto member = new Member(id);
    member->setEntranceYear(entranceYear)
        ->setFirstName(firstName)
        ->setLastName(lastName)
        ->setId(id);

    store->addMember(member);

    println();
    ok("New member with following information was added successfully:");
    printNewMemberInformation(member);
}

void addNewBook(Store *store)
{
    string name, author, isbn;
    uint publishYear, total;

    info("Enter new Book information:");

    name = promptString("Name:");
    author = promptString("Author name:");
    isbn = promptString("ISBN:");
    publishYear = (uint)promptInt("Publish Year:");
    total = (uint)promptInt("Total Number:");

    auto book = new Book();
    book->setName(name)
        ->setAuthor(author)
        ->setISBN(isbn)
        ->setPublishYear(publishYear)
        ->setTotal(total);

    store->addBook(book);

    println();
    ok("New book with following information was added successfully:");
    printNewBookInformation(book);
}

void borrowBookToMember(Store *store)
{
    info("Enter requested items to borrow a book:");

    auto isbn = promptString("Enter book ISBN:");
    auto book = store->findBookByISBN(isbn);
    if (book == NULL)
    {
        error("Could not find book with entered ISBN.");
        return;
    }

    if (!book->canBeBorrowed())
    {
        error("All books have been borrowed.");
        return;
    }

    auto memberId = promptString("Enter member ID:");
    auto member = store->findMemberById(memberId);
    if (member == NULL)
    {
        error("Member with entered ID is not registerd.");
        return;
    }

    if (!book->canBeBorrowedTo(member))
    {
        error("Member has already borrowed this book.");
        return;
    }

    book->borrowTo(member);

    ok("Book with ISBN (" + yellowBold(book->getISBN()) + ")");
    ok("has been successfully borrowed to member with ID (" + yellowBold(member->getId()) + ").");

    string s = "";
    if (book->getRemainingCount() > 1)
    {
        s = "s";
    }

    ok("Number of remaining book" + s + ": " + yellowBold(to_string(book->getRemainingCount())));

    return;
}

void takeBackBookFromMember(Store *store)
{
    info("Enter requested items to take back a book:");

    auto memberId = promptString("Enter member ID:");
    auto member = store->findMemberById(memberId);
    if (member == NULL)
    {
        error("Member with entered ID is not registerd.");
        return;
    }

    auto isbn = promptString("Enter book ISBN:");
    auto book = store->findBookByISBN(isbn);
    if (book == NULL)
    {
        error("Could not find book with entered ISBN.");
        return;
    }

    if (!member->hasBorrowedBook(book))
    {
        error("Book was not borrowed to member.");
        return;
    }

    book->takeBackFrom(member);

    ok("Book with ISBN (" + yellowBold(book->getISBN()) + ")");
    ok("has been successfully taken back from member with ID (" + yellowBold(member->getId()) + ").");
    ok("Number of book in library:" + yellowBold(to_string(book->getRemainingCount())));

    return;
}

void listMemberBorrowedBooks(Store *store)
{
    info("Enter requested items to see a list of books borrowed by a member:");

    auto memberId = promptString("Enter member ID:");
    auto member = store->findMemberById(memberId);
    if (member == NULL)
    {
        error("Member with entered ID is not registerd.");
        return;
    }

    println();
    info("Member with ID (" + yellowBold(member->getId()) + ") has borrowed " + yellowBold(to_string(member->getBorrowedBooksCount())) + " books.");
    println();
    info("List of books:");

    auto books = member->getBorrowedBooks();

    for (auto book = books.begin(); book != books.end(); book++)
    {
        printBorrowedBookInformation(*book);
    }
    println();
}
