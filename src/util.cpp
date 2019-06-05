#include <string>
#include <iostream>

#include "member.h"

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

string __colorize(const uint color, const string title)
{
    return "\x1b[1;38;5;" + to_string(color) + "m" + title + "\x1b[0m";
}

string red(const string title)
{
    const uint red = 9;
    return __colorize(red, title);
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

void __prompt(const string question)
{
    cout << __prepend() << "[" << blue("?") << "] " << question << " ";
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
    const string title = "ERROR";
    __log(red(title), message);
}

void info(const string message)
{
    const string title = "INFO";
    __log(magenta(title), message);
}

void ok(const string message)
{
    const string title = "OK";
    __log(green(title), message);
}

void warn(const string message)
{
    const string title = "WARN";
    __log(yellow(title), message);
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
    println(blue("ID") + ":" + __space(15-2) + member->getId());
    println(blue("First Name") + ":" + __space(15-10) + member->getFirstName());
    println(blue("Last Name") + ":" + __space(15-9) + member->getLastName());
    println(blue("Entrance Year") + ":" + __space(15-13) + to_string(member->getEntranceYear()));
}