#ifndef SONG_H
#define SONG_H

#include "db.h"
#include <string>
#include <iostream>

using namespace std;

class Song {
private:
    string songName;
    string artistName; 
    string genre;
public:
    Song();
    Song(string name, string artist, string genreName);
    string getName();
    string getArtistName();
    string getGenre();
    void displaySong();
};

#endif
