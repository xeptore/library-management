#include <string>
#include <iostream>

using namespace std;

void log(const string severity, const string message)
{
    cout << "[ " << severity << " ]: " << message << endl;
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
    log("ERROR", message);
}

void info(const string message)
{
    log("INFO", message);
}

void ok(const string message)
{
    log("OK", message);
}
