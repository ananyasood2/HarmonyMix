#ifndef LIBRARY_H
#define LIBRARY_H
#include "song.h"
#include "db.h"
#include <string>
#include <vector>
using namespace std;

class Library {
    private:
        vector<Song> songs;
    public:
        Library() = default;
        Song searchBySongName(string songName);
        Song searchByArtistName(string artistName); 
        Song searchByGenre(string genreName);
        bool addSong(Song *song);
};

#endif