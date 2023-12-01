#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include <vector>
#include "song.h"
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
    void deleteSong( Song& song); 
    void deletePlaylist();
    void displayPlaylist();
    ofstream sharePlaylist();
    vector<Song> reccommend(string artistName, string genre);

    //unit testing purposes 
    string getPlaylistName();
    Song at(unsigned int index);
};

#endif