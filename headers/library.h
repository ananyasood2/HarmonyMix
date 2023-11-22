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
        Library(); 
        Library(vector<Song> s);
        void searchBySongName(string songName);
        void searchByArtistName(string artistName); 
        Song searchByGenre(string genreName);
        bool addSong(Song *song);
};

#endif