#include "playlist.h"
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

