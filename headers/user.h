#ifndef USER_H
#define USER_H

#include "library.h"
#include "playlist.h"

#include <vector>
#include <string>

class User {
private:
    Library library;
    std::vector<Playlist> playlists;
    std::string username;
    std::string hashedPassword;
public:
    User() = default;
    User(std::string username, std::string password);
    bool login(std::string username, std::string password);
    bool logout();

};

#endif