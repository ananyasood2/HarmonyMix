#include "playlist.h"
#include "song.h"
#include <fstream>

Playlist::Playlist() {
    playlistName = "";
}

Playlist::Playlist(string playlist) {
    playlistName = playlist;
}

//adds the songName into the playlist vector  
void Playlist::addSong(const Song &song) {
   playlist.push_back(song);
}

//deletes a song from the playlist vector
void Playlist::deleteSong(Song &song) {
    for (auto iterate = playlist.begin(); iterate != playlist.end(); ++iterate) {
        if (iterate->getName() == song.getName()) {
            iterate = playlist.erase(iterate);
            --iterate;
        }
    }
}

string Playlist::getPlaylistName() const
{
    return this->playlistName;
}

Song Playlist::at(uint32_t index){
    return this->playlist.at(index);
}

Json::Value Playlist::toJson() const
{
    Json::Value playlist;
    // playlist[this->playlistName] = Json::Value(Json::objectValue);
    playlist[this->playlistName]["name"] = this->playlistName;
    playlist[this->playlistName]["songs"] = Json::Value(Json::arrayValue);
    for (auto song : this->playlist)
    {
        playlist[this->playlistName]["songs"].append(song.toJson());
    }
    return playlist;
}

const vector<Song> Playlist::getSongs() const
{
    return this->playlist;
}

// vector<Song> reccommend(User user, artist name, genre){

//     genreRec = this->userLibrary.searchByGenre();
//     artistRec = this->userLibrary.searchByArtistName();

//     return genreRec + artistRec;


    // UI
    // for each song in rec        
    //     std::cout << song.getName() << std::endl;

    // this->globalLibrary.searchByGenre();
    // this->globalLibrary.searchByArtistName();

// }
void Playlist::displayPlaylist() {
    for (Song song : playlist) {
        song.displaySong();
    }
}
void Playlist::deletePlaylist() {
    playlist.clear();
    playlistName = "";
}

ofstream Playlist::sharePlaylist() {
    string fileName = playlistName + ".txt";
    ofstream outputF(fileName, ios::out);
    if (outputF.is_open()) {
        for (Song &song : playlist) {
            outputF << song.getName() << ", " << song.getArtistName() << ", " << song.getGenre() << endl;
        }
        outputF.close();
        cout << "playlist file: " << fileName << " has been shared successfully" << endl;
    } else {
        cout << "Error: sharing playlist file has not been opened" << endl;
    }
    return outputF;
}

string Playlist::getPlaylistName() {
    return playlistName;
}

Song Playlist::at(unsigned int index) {
    return playlist.at(index);
}

vector<Song> Playlist::reccommend(string artistName, string genre) {
    Library libraryTest;
    vector<Song> genreRec;
    vector<Song> artistRec;

    genreRec = libraryTest.searchByGenre(genre);
    artistRec = libraryTest.searchByArtistName(artistName);

    genreRec.insert(genreRec.end(), artistRec.begin(), artistRec.end());

    return genreRec;
}
