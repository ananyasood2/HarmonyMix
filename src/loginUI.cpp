#include <string>
#include <iostream>
#include "userInterface.h"

using namespace std;

void UI::displayLogin(ostream &stream, istream &istream, User *user)
{
    int login = 0;
    string userName, password;
    stream << "1)Login" << endl;
    stream << "2)Create an Account" << endl;
    istream >> login;
    if (login == 1)
    {
        stream << "Enter your username: ";
        istream >> userName;
        stream << endl
             << "Enter your password: ";
        istream >> password;
        if (user->login(userName, password))
        {
            displayMainMenu(stream, istream, user);
        }
        else
        {
            stream << "Wrong username or password." << endl;
        }
    }
    else if (login == 2)
    {
        stream << "Enter your username: ";
        istream >> userName;
        stream << endl
             << "Enter your password: ";
        istream >> password;
        if (user->create_account(userName, password))
        {
            stream << "Account created" << endl;
            displayMainMenu(stream, istream, user);
        }
        else
        {
            stream << "Account already exists" << endl;
        }
    }
    else
    {
        stream << "Invalid input, try again: ";
        istream >> login;
    }
}
