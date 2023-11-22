#include "library.h"

//checking to see if there is a song that exists according to genre within the playlist vector 
void Library::searchByGenre(string genreName) {

    for (Song &song : songs) {
        if (song.getGenre() == genreName) {
           //prints out song information
           song.displaySongs()
        }
    }
}

//addings a new song into the library
void Library::addToLibrary(string songName, string artistName, string genreName) {
    Song newSong(songName, artistName, genreName); 

    //checking to make sure that a duplicate song wasn't added
    if (newSong.duplicateSong(newSong) == false) {
        songs.push_back(newSong); 
    }
    
}

//checking to see if there is a duplicate song in the library 
bool Library::duplicateSong(Song *song) {
    bool decision = false;

    for (Song &songDuplicate : songs) {
        if (songDuplicate.getName() == song.getName() && songDuplicate.getArtistName() == song.getArtistName()) {
            return true;
        }
    }
}
