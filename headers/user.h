#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "library.h"
#include "playlist.h"
#include "db.h"
class User {
private:
    Library library;    
    Db db;
    std::vector<Playlist> playlists;
    std::string username;
    std::string hashedPassword;    
public:
    User() = default;
    bool login(const std::string &username, const std::string &password);
    bool logout();

    std::string get_username() const;
    std::string get_password() const;
    std::vector<Song> get_library() const;    
    std::vector<Playlist> get_playlists() const;    
    Playlist get_playlist(const std::string& playlistName) const;
    void createPlaylist(const std::string& playlistName);
    bool create_account(const std::string &username, const std::string &password);
    void addSongToLibrary(Song& song);
    void deleteSongFromLibrary(const std::string& song);
    void addSongToPlaylist(const Playlist &playlist, const Song& song);
    void deleteSongFromPlaylist(const std::string &playlist, const std::string& song);

};

#endif