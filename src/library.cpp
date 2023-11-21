#include "db.h"
#include "library.h"

//searches songs by song name and returns the user selected song
Song Library::searchBySongName(string songName) {
    vector <Song> matchingSongs;

    for (Song &song : songs) {
        if (song.getName() == songName) {
            matchingSongs.push_back(song);
        }
    }
    //prints out song information
    displaySong(matchingSongs);
}

//searches the songs by artist name and returns the songs created by that artist 
Song Library::searchByArtistName(string artistName) {
    vector <Song> matchingSongs;

    for (Song &song : songs) {
        if (song.getName() == artistName) {
            matchingSongs.push_back(song);
        }
    }
    //prints out song information
    displaySong(matchingSongs);
}
