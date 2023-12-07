#include <filesystem>
#include <fstream>
#include <iostream>
#include "json/json.h"
#include "song.h"
#include "user.h"
#include "db.h"

namespace fs = std::filesystem;

void Db::save()
{
    std::fstream usersdb (fs::current_path().append("usersdb.json"),  std::ios::in | std::ios::out | std::ios::trunc);
    usersdb << this->db;
    usersdb.flush();
    usersdb.close();
}

Db::Db()
{
    
    std::fstream usersdb (fs::current_path().append("usersdb.json"),  std::ios::in | std::ios::out | std::ios::app);
    if(fs::is_empty(fs::current_path().append("usersdb.json"))){
        this->db = Json::nullValue;
        usersdb << this->db;
        usersdb.flush();
    }
    else {
        
        usersdb >> this->db;
        usersdb.flush();
    }
    
    

    //users
        // <username>
            // library
            // playlists
        // <usernameb>

}

Db::~Db()
{
    this->save();    
}


bool Db::user_exists(const std::string &username)  const {
    return this->db.isMember(username);
}

bool Db::create_account(const std::string &username, const std::string &password)
{
    if (this->user_exists(username)){        
        return false;
    }
    else {
        std::hash<std::string> str_hash;        
        this->db[username]["password"] = str_hash(password); 
        this->db[username]["library"] = Json::Value(Json::objectValue);
        this->db[username]["playlists"] = Json::Value(Json::objectValue);        
        std::fstream usersdb (fs::current_path().append("usersdb.json"),  std::ios::in | std::ios::out | std::ios::trunc);
        usersdb << this->db;
        usersdb.flush();
        return true;
    }
    return false;
}

size_t Db::get_password(const std::string &username)
{
    return this->db[username]["password"].asUInt64();
}

std::vector<Playlist> Db::get_playlists(const std::string &user) const
{
    auto playlists_json = this->db[user]["playlists"];
    std::vector<Playlist> playlists;
    for(auto playlist : playlists_json){
        Playlist _playlist(playlist["name"].asString());
        Song song;
        for(auto song : playlist["songs"]){
            _playlist.addSong(Song(song["name"].asString(), song["artist"].asString(), song["genre"].asString()));
        }
        playlists.push_back(_playlist);
    }
    std::cout << playlists.size() << std::endl;
    return playlists;
}

void Db::add_song_to_playlist(const std::string &user, const Playlist &playlist, const Song &song)
{
    this->db[user]["playlists"][playlist.getPlaylistName()]["songs"][song.getName()] = song.toJson();
    this->save();
}

void Db::remove_song_from_playlist(const std::string &user, const std::string &playlist, const std::string &song)
{
    this->db[user]["playlists"][playlist]["songs"][song].removeMember(song);
    this->save();
}

std::vector<Song> Db::get_library(const std::string &user) const
{
    auto library_json = this->db[user]["library"];
    std::vector<Song> library;
    for(auto song : library_json){
        library.push_back(Song(song["name"].asString(), song["artist"].asString(), song["genre"].asString()));
    }
    return library;
}

void Db::add_song_to_library(const std::string &user, const Song &song)
{
    this->db[user]["library"][song.getName()] = song.toJson();
    this->save();
}

void Db::remove_song_from_library(const std::string &user, const std::string &song_name)
{
    this->db[user]["library"].removeMember(song_name);
    this->save();
}

void Db::add_playlist(const std::string &user, const Playlist &playlist) 
{
    this->db[user]["playlists"] = playlist.toJson();
    this->save();
}

void Db::remove_playlist(const std::string &user, const Playlist &playlist) 
{
    this->db[user]["playlists"].removeMember(playlist.getPlaylistName());
    this->save();
}
