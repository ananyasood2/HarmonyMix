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
