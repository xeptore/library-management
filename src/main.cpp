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

Member *addNewMember(Store *store);

int main()
{
    auto store = new Store();

    banner();
    help();
    int action;
    while ((action = getaction()) == -1)
    {
        error("Invalid input.");
        error("Just enter number of the option you want.");
        help();
    }

    switch (action)
    {
    case 0:
    {
        exit(0);
    }
    case 1:
    {
        auto member = addNewMember(store);
        if (member != NULL)
        {
            println();
            ok("New member added successfully:");
            printNewMemberInformation(member);
        }
        else
        {
            error("Unable to register member.");
            error("Try again, please.");
        }
        break;
    }
    case 3:
    {
    }
    default:
        break;
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
    println("[ " + yellow("4") + " ] " + "Unborrow a book from a member");
    println("[ " + yellow("5") + " ] " + "Show a list of borrowed books from a member");
    println("[ " + yellow("6") + " ] " + "Show a list of books in the library");
    println("[ " + yellow("7") + " ] " + "Show a list of books in the library");
    println("[ " + grey("0") + " ] " + "Exit");
    cout << endl;
}

int getaction()
{
    print("What can i do for you: ");
    int action;
    cin >> action;
    if (cin.fail() || action > 7 || action < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return action;
}

Member *addNewMember(Store *store)
{
    string firstName, lastName, id;
    uint entranceYear;

    println();
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

    return member;
}
