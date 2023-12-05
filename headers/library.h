#ifndef LIBRARY_H
#define LIBRARY_H
#include "song.h"
#include <string>
#include <vector>
using namespace std;

class Library {
    private:
        vector<Song> songs;
    public:
        Library(); 
        Library(vector<Song> s);
        void searchBySongName(string songName);
        void searchByArtistName(string artistName); 
        void searchByGenre(string genreName);
        void addToLibrary(string songName, string artistName, string genreName);
        bool duplicateSong(Song *song);
        std::vector<Song> getSongs() const;
};

#endif