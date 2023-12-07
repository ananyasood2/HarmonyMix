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
    this->library = Library();
    this->playlists = std::vector<Playlist>();
    return true;
}

std::string User::get_username() const
{
    return this->username;
}

std::string User::get_password() const
{
    return this->hashedPassword;
}

Library User::get_library() const
{
    return this->library;
}

std::vector<Playlist> User::get_playlists() const
{
    return this->playlists;
}

Playlist* User::get_playlist(const std::string &playlistName)
{
    for(auto it = this->playlists.begin(); it != this->playlists.end(); it++){
        if(it->getPlaylistName() == playlistName){
            return &(*it);
        }
    }
    return nullptr;
}

void User::createPlaylist(const std::string &playlistName)
{
    for(auto it = playlists.begin(); it != playlists.end(); it++){
        if(it->getPlaylistName() == playlistName){
            return;
        }
    }
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
    this->library.removeFromLibrary(song);
    db.remove_song_from_library(this->username, song);   
}

void User::addSongToPlaylist(const std::string &playlist, const Song &song)
{
    auto playlist_ptr = this->get_playlist(playlist);
    if(playlist_ptr == nullptr){
        return;
    }
    for(auto _song : playlist_ptr->getSongs()){
        if(_song.getName() == song.getName()){
            return;
        }
    }
    playlist_ptr->addSong(song);
    db.add_song_to_playlist(this->username, playlist, song);
}

void User::deleteSongFromPlaylist(const std::string &playlist, const std::string &song)
{
    Song s(song, "", "");
    this->get_playlist(playlist)->deleteSong(s);
    db.remove_song_from_playlist(this->username, playlist, song);
}
