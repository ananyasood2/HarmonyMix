#include "db.h"
#include <json/json.h>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;
Db::Db()
{
    if(fs::exists(fs::current_path().append("users/usersdb.json"))){
        std::cout << "usersdb exists" << std::endl;
    }
    else {
        
    }
    Json::Value json;
    json["users"]["usernamea"]["playlists"] = "";
    //users
        // <username>
            // library
            // playlists
        // <usernameb>
    fs::create_directory("users");
    std::ofstream usersdb;
    usersdb.open("users/usersdb.json");
    usersdb << json;
    usersdb.close();
}

void Db::add_song_to_library(User *user)
{

}

bool Db::user_exists(std::string username){
    return false;
}
