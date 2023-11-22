#ifndef LIBRARY_H
#define LIBRARY_H
#include "song.h"
#include "db.h"
#include <string>
#include <vector>
using namespace std;

class Library : public Song {
    private:
        vector<Song> songs;
    public:
        Library() = default;
        void searchBySongName(string songName);
        void searchByArtistName(string artistName); 
        void searchByGenre(string genreName);
        void addToLibrary(string songName, string artistName, string genreName);
        bool duplicateSong(Song *song);
};

#endif