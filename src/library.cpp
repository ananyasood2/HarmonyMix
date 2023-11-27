
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


//checking to see if there is a song that exists according to genre within the playlist vector 
vector<Song> Library::searchByGenre(string genreName) {
    vector<Song> correctSong; 

    for (Song &song : songs) {
        if (song.getGenre() == genreName) {
           //prints out song information
           correctSong.push_back(song);
        }
    }
    return correctSong;
}

//addings a new song into the library
void Library::addToLibrary(Song &song) {

    //checking to make sure that a duplicate song wasn't added
    if (duplicateSong(song) == false) {
        songs.push_back(song); 
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

//.at function for unit tests
Song Library::at(unsigned int i) {
    return songs.at(i);
}

