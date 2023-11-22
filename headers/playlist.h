#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include <vector>
#include "song.h"

using namespace std;

class Playlist {
private:
    vector<Song> songs;
    string playlistName;
public:
    Playlist() = default;
    void addSong(Song songName);
    void deleteSong(Song songName); 
};

#endif

