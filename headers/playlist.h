#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include <vector>
#include "song.h"

using namespace std;

class Playlist : public Song {
private:
    vector<Song> playlist;
    string playlistName;
public:
    Playlist();
    Playlist(string playlist);
    void addSong(const Song& song);
    void deleteSong( Song& song); 
    void displayPlaylist();
    Song at(unsigned int index);
};

#endif

