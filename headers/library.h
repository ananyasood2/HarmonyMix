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

        std::vector<Song> getSongs() const;
        vector<Song> searchBySongName(string songName);
        vector<Song> searchByArtistName(string artistName); 
        vector<Song> searchByGenre(string genreName);
        void addToLibrary(Song &song);
        bool duplicateSong(Song &song);

        //for the unit tests writing a .at function
        Song at(unsigned int i);

};

#endif