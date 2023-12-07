#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "library.h"
#include "playlist.h"
#include "user.h"
#include <vector>
#include <string>

class UI {
private:
    User user;
    Library library;
    std::vector<Playlist> playlists;
    Playlist playlist;
    
public:
    UI() = default;
    void displayLogin(ostream &stream, istream &istream, User *user);
    void displayMainMenu(ostream &stream, istream &istream, User *user);
    void displayLibraryMenu(ostream &stream, istream &istream, User *user);
    void displayPlaylistMenu(ostream &stream, istream &istream, User *user);

};
#endif

