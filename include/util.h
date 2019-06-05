#include <iostream>
#include <string>

#include "member.h"
#include "book.h"

using namespace std;

int promptInt(const string question);
string promptString(const string question);
float promptFloat(const string question);
double promptDouble(const string question);

void error(const string message);
void info(const string message);
void ok(const string message);
void warn(const string message);

void print(const string message);
void println(const string message);
void println();

string red(const string str);
string green(const string str);
string grey(const string str);
string magenta(const string str);
string yellow(const string str);
string blue(const string str);

string redBold(const string str);
string greenBold(const string str);
string greyBold(const string str);
string magentaBold(const string str);
string yellowBold(const string str);
string blueBold(const string str);

void printNewMemberInformation(Member *member);
void printNewBookInformation(Book *book);

void printBorrowedBookInformation(Book *book);
