#include <iostream>
#include <limits>

#include "book.h"
#include "member.h"
#include "store.h"
#include "util.h"

using namespace std;

void banner();
void help();
uint getaction();

bool addNewMember();

int main() {
    banner();
    help();
    uint action;
    while ((action = getaction()) == 0)
    {
        error("Invalid input.");
        error("Just enter number of the option you want.");
        help();
    }

    switch (action)
    {
        case 1:
        {
            addNewMember();
            ok("New member added successfully");
            break;
        }
        default:
            break;
    }
    return 0;
}

void banner()
{
    cout << endl;
    cout << "  " << "******************************************" << endl;
    cout << "  " << "*                                        *" << endl;
    cout << "  " << "*         Library Management App         *" << endl;
    cout << "  " << "*                                        *" << endl;
    cout << "  " << "******************************************" << endl;
}

void help()
{
    cout << endl << endl;
    cout << "  Choose one the following options:" << endl;
    cout << "  " << "[ " << yellow("1") << " ] " << "Add a new member" << endl;
    cout << "  " << "[ " << yellow("2") << " ] " << "Add a new book to library" << endl;
    cout << "  " << "[ " << yellow("3") << " ] " << "Borrow a book to a member" << endl;
    cout << "  " << "[ " << yellow("4") << " ] " << "Unborrow a book from a member" << endl;
    cout << "  " << "[ " << yellow("5") << " ] " << "Show a list of borrowed books from a member" << endl;
    cout << "  " << "[ " << yellow("6") << " ] " << "Show a list of books in the library" << endl;
    cout << "  " << "[ " << yellow("7") << " ] " << "Show a list of books in the library" << endl;
    cout << endl;
}

uint getaction()
{
    cout << "  " << "What can i do for you: ";
    uint action;
    cin >> action;
    if (cin.fail() || action > 7 || action < 1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 0;
    }
    return action;
}

bool addNewMember()
{
    return true;
}
