#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include <vector>
#include "song.h"
#include "json/json.h"

using namespace std;

class Playlist {
private:
    vector<Song> playlist;
    string playlistName;
public:
    Playlist();
    Playlist(string playlist);
    void addSong(const Song& song);
    void deleteSong(Song& song);     
    string getPlaylistName() const;
    Song at (uint32_t index);
    Json::Value toJson() const;
    const vector<Song> getSongs() const;
};

#endif

