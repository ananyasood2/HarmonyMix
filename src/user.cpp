#include <string>
#include <iostream>
#include <algorithm>
#include "library.h"
#include "user.h"
#include "db.h"


bool User::login(const std::string &username, const std::string &password){
    if (db.user_exists(username)){
        std::hash<std::string> str_hash;
        if (db.get_password(username) == str_hash(password)){
            this->username = username;
            this->db = Db();     
            this->library = Library(this->db.get_library(this->username)); 
            this->playlists = this->db.get_playlists(this->username);    
            return true;
        } 
    }
    return false;
}

bool User::logout() {
    return false;
}

std::string User::get_username() const
{
    return this->username;
}

std::string User::get_password() const
{
    return this->hashedPassword;
}

std::vector<Song> User::get_library() const
{
    return this->library.getSongs();
}

std::vector<Playlist> User::get_playlists() const
{
    return this->playlists;
}

Playlist User::get_playlist(const std::string &playlistName) const
{
    auto it = std::find_if(this->playlists.begin(), this->playlists.end(), [&playlistName](const Playlist &playlist){
        return playlist.getPlaylistName() == playlistName;
    });
    return *it;
}

void User::createPlaylist(const std::string &playlistName)
{
    Playlist playlist = Playlist(playlistName);
    this->playlists.push_back(playlist);
    this->db.add_playlist(this->username, playlist);
}

bool User::create_account(const std::string &username, const std::string &password)
{
    return this->db.create_account(username, password);
}

void User::addSongToLibrary(Song &song)
{
    this->library.addToLibrary(song);
    db.add_song_to_library(this->username, song);
}

void User::deleteSongFromLibrary(const std::string &song)
{
    db.remove_song_from_library(this->username, song);   
}

void User::addSongToPlaylist(const Playlist &playlist, const Song &song)
{
    db.add_song_to_playlist(this->username, playlist, song);
}

void User::deleteSongFromPlaylist(const std::string &playlist, const std::string &song)
{
    db.remove_song_from_playlist(this->username, playlist, song);
}
