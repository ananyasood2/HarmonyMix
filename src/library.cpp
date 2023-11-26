
#include "db.h"
#include "library.h"
#include "song.h"

Library::Library() {

}

Library::Library(vector<Song> s) {
    songs = s;
}

//searches songs by song name and returns the user selected song
void Library::searchBySongName(string songName) {

    for (Song &song : songs) {
        if (song.getName() == songName) {
            //prints out song information
            song.displaySong();
        }
    }
}

//searches the songs by artist name and returns the songs created by that artist 
void Library::searchByArtistName(string artistName) {

    for (Song &song : songs) {
        if (song.getArtistName() == artistName) {
            //prints out song information
            song.displaySong();
        }
    }
}


//checking to see if there is a song that exists according to genre within the playlist vector 
void Library::searchByGenre(string genreName) {

    for (Song &song : songs) {
        if (song.getGenre() == genreName) {
           //prints out song information
           song.displaySong();
        }
    }
}

//addings a new song into the library
void Library::addToLibrary(string songName, string artistName, string genreName) {
    Song newSong(songName, artistName, genreName); 

    //checking to make sure that a duplicate song wasn't added
    if (duplicateSong(newSong) == false) {
        songs.push_back(newSong); 
    }
    
}

//checking to see if there is a duplicate song in the library 
bool Library::duplicateSong(Song &song) {
    bool decision = false;

    for (Song &songDuplicate : songs) {
        if (songDuplicate.getName() == song.getName() && songDuplicate.getArtistName() == song.getArtistName()) {
            return true;
        }
    }
}
