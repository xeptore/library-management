#include <string>
#include <iostream>

using namespace std;

void log(const string severity, const string message)
{
    cout << "[ " << severity << " ] : " << message << endl;
}

string colorize(const uint color, const string title)
{
    return "\x1b[1;38;5;" + to_string(color) + "m" + title + "\x1b[0m";
}

string red(const string title)
{
    const uint red = 9;
    return colorize(red, title);
}

string green(const string title)
{
    const uint green = 10;
    return colorize(green, title);
}

string magenta(const string title)
{
    const uint magenta = 93;
    return colorize(magenta, title);
}

string yellow(const string title)
{
    const uint yellow = 226;
    return colorize(yellow, title);
}

int promptInt(const string question)
{
    int input;
    cin >> input;
    return input;
}

string promptString(const string question)
{
    string input;
    getline(cin, input);
    return input;
}

float promptFloat(const string question)
{
    float input;
    cin >> input;
    return input;
}

double promptDouble(const string question)
{
    double input;
    cin >> input;
    return input;
}

void error(const string message)
{
    const string title = "ERROR";
    log(red(title), message);
}

void info(const string message)
{
    const string title = "INFO";
    log(magenta(title), message);
}

void ok(const string message)
{
    const string title = "OK";
    log(green(title), message);
}

void warn(const string message)
{
    const string title = "WARN";
    log(yellow(title), message);
}
