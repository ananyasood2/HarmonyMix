#include "db.h"
#include "library.h"
#include "song.h"

Library::Library() {

}

Library::Library(vector<Song> s) {
    songs = s;
}

//searches songs by song name and returns the user selected song
vector<Song> Library::searchBySongName(string songName) {
    vector<Song> correctSong;


    for (Song &song : songs) {
        if (song.getName() == songName) {
            //prints out song information
            correctSong.push_back(song);
        }
    }
    return correctSong;
}

//searches the songs by artist name and returns the songs created by that artist 
vector<Song> Library::searchByArtistName(string artistName) {
    vector<Song> correctSong; 

    for (Song &song : songs) {
        if (song.getArtistName() == artistName) {
            //prints out song information
            correctSong.push_back(song);
        }
    }
    return correctSong;
}
