#include "library.h"

//checking to see if there is a song that exists according to genre within the playlist vector 
Song Library::searchByGenre(string genreName) {

    for (Song &song : songs) {
        if (song.getGenre() == genreName) {
           //prints out song information
           song.displaySongs()
        }
    }
}

//checking to see if there is a duplicate song in the library 
bool Library::addSong(Song *song) {
    bool decision = true;

    for (Song &songDuplicate : songs) {
        if (songDuplicate.getName() == song.getName() && songDuplicate.getArtistName() == song.getArtistName()) {
            return false;
        }
    }
}
