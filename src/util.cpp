#include <string>
#include <iostream>

#include "member.h"
#include "book.h"

using namespace std;

string __prepend()
{
    return "  ";
}

string __space(const uint n)
{
    string s;
    for (uint i = 0; i < n; i++)
    {
        s += " ";
    }
    return s;
}

void __log(const string severity, const string message)
{
    cout << __prepend() << "[ " << severity << " ]: " << message << endl;
}

string __colorize(const uint color, const string title, bool bold = false)
{
    if (bold)
    {
        return "\x1b[1;38;5;" + to_string(color) + "m" + title + "\x1b[0m";
    }
    return "\x1b[0;38;5;" + to_string(color) + "m" + title + "\x1b[0m";
}

string red(const string title)
{
    const uint red = 9;
    return __colorize(red, title);
}

string darkRed(const string str)
{
    const uint darkred = 88;
    return __colorize(darkred, str);
}

string green(const string title)
{
    const uint green = 10;
    return __colorize(green, title);
}

string grey(const string str)
{
    const uint grey = 241;
    return __colorize(grey, str);
}

string magenta(const string title)
{
    const uint magenta = 93;
    return __colorize(magenta, title);
}

string pink(const string str)
{
    const uint pink = 171;
    return __colorize(pink, str);
}

string yellow(const string title)
{
    const uint yellow = 226;
    return __colorize(yellow, title);
}

string blue(const string title)
{
    const uint blue = 14;
    return __colorize(blue, title);
}

string redBold(const string str)
{
    const uint red = 9;
    return __colorize(red, str, true);
}

string darkRedBold(const string str)
{
    const uint darkred = 88;
    return __colorize(darkred, str, true);
}

string greenBold(const string str)
{
    const uint green = 10;
    return __colorize(green, str, true);
}

string greyBold(const string str)
{
    const uint grey = 241;
    return __colorize(grey, str, true);
}

string magentaBold(const string str)
{
    const uint magenta = 93;
    return __colorize(magenta, str, true);
}

string pinkBold(const string str)
{
    const uint pink = 171;
    return __colorize(pink, str, true);
}

string yellowBold(const string str)
{
    const uint yellow = 226;
    return __colorize(yellow, str, true);
}

string blueBold(const string str)
{
    const uint blue = 14;
    return __colorize(blue, str, true);
}

void __prompt(const string question)
{
    cout << __prepend() << "[" << blueBold("?") << "] " << blue(question) << " ";
}

int promptInt(const string question)
{
    int input;
    __prompt(question);
    cin >> input;
    return input;
}

string promptString(const string question)
{
    string input;
    __prompt(question);

    // there is a problem using getline() function
    // which happens if `cin` was called right before calling getline()
    // and getline() thinks that entered `\n` after `cin` is telling it stop reading input stream,
    // by ignoring `\n` charachter, we make sure the user __really__ inputs anything.
    // read more at: https://mathbits.com/MathBits/CompSci/APstrings/APgetline.html.
    getline(cin, input);
    if (input.length() != 0)
    {
        return input;
    }
    getline(cin, input);
    return input;
}

float promptFloat(const string question)
{
    float input;
    __prompt(question);
    cin >> input;
    return input;
}

double promptDouble(const string question)
{
    double input;
    __prompt(question);
    cin >> input;
    return input;
}

void error(const string message)
{
    cout << endl;
    const string title = "ERROR";
    __log(redBold(title), message);
}

void info(const string message)
{
    const string title = "INFO";
    __log(magentaBold(title), message);
}

void ok(const string message)
{
    const string title = "OK";
    __log(greenBold(title), message);
}

void warn(const string message)
{
    const string title = "WARN";
    __log(yellowBold(title), message);
}

void print(const string message)
{
    cout << __prepend() << message;
}

void println(const string message)
{
    cout << __prepend() << message << endl;
}

void println()
{
    cout << endl;
}

void printNewMemberInformation(Member *member)
{
    const uint maxLen = 15;
    println(blueBold("ID") + ":" + __space(maxLen - 2) + member->getId());
    println(blueBold("First Name") + ":" + __space(maxLen - 10) + member->getFirstName());
    println(blueBold("Last Name") + ":" + __space(maxLen - 9) + member->getLastName());
    println(blueBold("Entrance Year") + ":" + __space(maxLen - 13) + to_string(member->getEntranceYear()));
}

void printNewBookInformation(Book *book)
{
    const uint maxLen = 15;
    println(blueBold("Name") + ":" + __space(maxLen - 4) + book->getName());
    println(blueBold("Author Name") + ":" + __space(maxLen - 11) + book->getAuthor());
    println(blueBold("ISBN") + ":" + __space(maxLen - 4) + book->getISBN());
    println(blueBold("Publish Year") + ":" + __space(maxLen - 12) + to_string(book->getPublishYear()));
    println(blueBold("Total") + ":" + __space(maxLen - 5) + to_string(book->getTotal()));
}

void printBorrowedBookInformation(Book *book)
{
    const uint maxLen = 15;
    println(pinkBold("Name") + ":" + __space(maxLen - 4) + book->getName());
    println(pinkBold("Author Name") + ":" + __space(maxLen - 11) + book->getAuthor());
    println(pinkBold("ISBN") + ":" + __space(maxLen - 4) + book->getISBN());
    println(pinkBold("Publish Year") + ":" + __space(maxLen - 12) + to_string(book->getPublishYear()));
    println(pinkBold("Total") + ":" + __space(maxLen - 5) + to_string(book->getTotal()));
}

void printRegisteredBookInformation(Book *book)
{
    const uint maxLen = 15;
    println(blueBold("Name") + ":" + __space(maxLen - 4) + book->getName());
    println(blueBold("Author Name") + ":" + __space(maxLen - 11) + book->getAuthor());
    println(blueBold("ISBN") + ":" + __space(maxLen - 4) + book->getISBN());
    println(blueBold("Publish Year") + ":" + __space(maxLen - 12) + to_string(book->getPublishYear()));
    println(blueBold("Total") + ":" + __space(maxLen - 5) + to_string(book->getTotal()));
    println(blueBold("Borrowed") + ":" + __space(maxLen - 8) + to_string(book->getTotal() - book->getRemainingCount()));
    println(blueBold("Remaining") + ":" + __space(maxLen - 9) + to_string(book->getRemainingCount()));
}

void printRegisteredMemberInformation(Member *member)
{
    const uint maxLen = 27;
    println(blueBold("ID") + ":" + __space(maxLen - 2) + member->getId());
    println(blueBold("First Name") + ":" + __space(maxLen - 10) + member->getFirstName());
    println(blueBold("Last Name") + ":" + __space(maxLen - 9) + member->getLastName());
    println(blueBold("Entrance Year") + ":" + __space(maxLen - 13) + to_string(member->getEntranceYear()));
    println(blueBold("Number of Borrowed Books") + ":" + __space(maxLen - 24) + to_string(member->getBorrowedBooksCount()));
}
