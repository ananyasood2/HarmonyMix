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
   
    
public:
    UI() = default;
    void displayLogin();
    void displayMainMenu();
    void displayLibraryMenu();
    void displayPlaylistMenu();

};
#endif

