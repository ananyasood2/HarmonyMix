#include "user.h"
#include <string>
#include <iostream>

User::User(std::string username, std::string password)
{
    std::cout << "Hello, World" << std::endl;
}

bool User::login(std::string username, std::string password){
    return false;
}

bool User::logout() {
    return false;
}
