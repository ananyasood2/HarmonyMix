#ifndef SONG_H
#define SONG_H

#include "db.h"
#include "library.h"
#include <string>

using namespace std;

class Song {
private:
    string songName;
    string artistName; 
    string genre;
public:
    Song() = default;
    string getName();
    string getArtistName();
    string getGenre();
};

#endif
