#include "song.h"

Song::Song() {
    songName = "";
    artistName = "";
    genre = "";
}

Song::Song(string name, string artist, string genreName) {
    songName = name;
    artistName = artist;
    genre = genreName;
}

string Song::getName() {
    return songName;
}

string Song::getArtistName() {
    return artistName;
}

string Song::getGenre() {
    return genre;
}

void Song::displaySong() {
    cout << "Song Name: " << getName() << " " << "Artist Name: " << getArtistName() << " " << "Song Genre: " << getGenre() << endl;
    //newline after song information
    cout << endl;
}