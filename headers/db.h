#ifndef DB_H
#define DB_H
#include <string>
#include "json/json.h"
#include "song.h"
#include "playlist.h"
class Db {
private:
    Json::Value db;
    void save();
public:
    Db();
    ~Db();
    bool user_exists(const std::string &username) const;
    bool create_account(const std::string &username, const std::string &password);
    size_t get_password(const std::string &username);

    std::vector<Playlist> get_playlists(const std::string &user) const;
    void add_song_to_playlist(const std::string &user, const Playlist &playlist, const Song &song);
    void remove_song_from_playlist(const std::string &user, const std::string &playlist, const std::string &song);

    std::vector<Song> get_library(const std::string &user) const;
    void add_song_to_library(const std::string &user, const Song &song);
    void remove_song_from_library(const std::string &user, const std::string &song);

    void add_playlist(const std::string &user, const Playlist &playlist);
    void remove_playlist(const std::string &user, const Playlist &playlist);

};

#endif
