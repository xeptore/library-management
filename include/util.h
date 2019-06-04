#include <iostream>
#include <string>

using namespace std;

int promptInt(const string question);
string promptString(const string question);
float promptFloat(const string question);
double promptDouble(const string question);

void error(const string message);
void info(const string message);
void ok(const string message);
void warn(const string message);

string red(const string str);
string green(const string str);
string magenta(const string str);
string yellow(const string str);
string blue(const string str);
