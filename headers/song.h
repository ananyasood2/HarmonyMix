#ifndef SONG_H
#define SONG_H
#include <string>
#include <iostream>

#include "json/json.h"

using namespace std;

class Song {
private:
    string songName;
    string artistName; 
    string genre;
public:
    Song();
    Song(string name, string artist, string genreName);
    string getName() const;
    string getArtistName() const;
    string getGenre() const;
    void displaySong(ostream &stream) const;
    Json::Value toJson() const; 

    friend bool operator!=(const Song& lhs, const Song& rhs){
        return !(lhs.songName.compare(rhs.songName) == 0);
    }
};

#endif
