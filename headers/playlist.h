#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include <vector>
#include "song.h"

using namespace std;

class Playlist {
private:
    vector<Song> playlist;
    string playlistName;
public:
    Playlist();
    Playlist(string playlist);
    void addSong(const Song& song);
    void deleteSong( Song& song); 
    void deletePlaylist();
    void displayPlaylist();
    string getPlaylistName();
    Song sharePlaylist();
    Song at(unsigned int index);
};

#endif

