#include "song.h"

string Song::getName() {
    return songName;
}

string Song::getArtistName() {
    return artistName;
}

string Song::getGenre() {
    return genre;
}

void Song::displaySong(const vector<Song> &songs) {
    for (Song& song : songs) {
        cout << "Song Name: " << song.getName() << endl;
        cout << "Artist Name: " << song.getArtistName() << endl;
        cout << "Song Genre: " << song.getGenre() << endl;
        //newline after song information
        cout << endl;
    }
    
}