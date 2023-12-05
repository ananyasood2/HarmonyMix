#include <string>
#include <iostream>
#include "userInterface.h"

using namespace std;

void UI::displayLogin(ostream &stream, User *user)
{
    int login = 0;
    string userName, password;
    cout << "1)Login" << endl;
    cout << "2)Create an Account" << endl;
    cin >> login;
    if (login == 1)
    {
        cout << "Enter your username: ";
        cin >> userName;
        cout << endl
             << "Enter your password: ";
        cin >> password;
        if (user->login(userName, password))
        {
            displayMainMenu(stream, user);
        }
        else
        {
            cout << "Wrong username or password." << endl;
        }
    }
    else if (login == 2)
    {
        cout << "Enter your username: ";
        cin >> userName;
        cout << endl
             << "Enter your password: ";
        cin >> password;
        if (user->create_account(userName, password))
        {
            cout << "Account created" << endl;
            displayMainMenu(stream, user);
        }
        else
        {
            cout << "Account already exists" << endl;
        }
    }
    else
    {
        cout << "Invalid input, try again: ";
        cin >> login;
    }
}
