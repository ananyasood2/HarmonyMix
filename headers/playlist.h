#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include <vector>
#include "song.h"
#include "json/json.h"
#include "library.h"

using namespace std;

class Playlist {
private:
    vector<Song> playlist;
    string playlistName;
public:
    Playlist();
    Playlist(string playlist);
    void addSong(const Song& song);
    string getPlaylistName() const;
    Json::Value toJson() const;
    const vector<Song> getSongs() const;
    void deleteSong( Song& song); 
    void deletePlaylist();
    void displayPlaylist(ostream &stream);
    ofstream sharePlaylist();
    vector<Song> reccommend(Library library, string artistName, string genre);

    //unit testing purposes 
    string getPlaylistName();
    Song at(unsigned int index);
};

#endif