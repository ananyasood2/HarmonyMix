#include "song.h"
#include "json/json.h"

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

string Song::getName() const {
    return songName;
}

string Song::getArtistName() const {
    return artistName;
}

string Song::getGenre() const {
    return genre;
}

void Song::displaySong(ostream &stream) const {
    stream << "Song Name: " << getName() << " " << "Artist Name: " << getArtistName() << " " << "Song Genre: " << getGenre() << endl;
    //newline after song information
    stream << endl;
}

Json::Value Song::toJson() const
{
    Json::Value song;
    song["name"] = this->songName;
    song["artist"] = this->artistName;
    song["genre"] = this->genre;
    return song;
}
