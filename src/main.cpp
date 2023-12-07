#include <iostream>
#include <filesystem>
#include <json/json.h>
#include <string>
#include <fstream>
#include "userInterface.h"
#include "db.h"
namespace fs = std::filesystem;

int main(){
    User user;
    UI ui;
    // if(user.create_account("test", "test")) {
    //     std::cout << "Account created" << std::endl;
    // }
    // else {
    //     std::cout << "Account already exists" << std::endl;
    // }
    // user.login("test", "test");
    // user.addSongToLibrary(Song("Call Me Maybe", "Carley Rae Jepsen", "Pop"));
    // user.deleteSongFromLibrary(Song("Call Me Maybe", "Carley Rae Jepsen", "Pop"));

    ui.displayLogin(cout, cin, &user);
}