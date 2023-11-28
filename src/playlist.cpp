#include "playlist.h"

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

Song Playlist::at(unsigned int index) {
    return playlist.at(index);
}

string Playlist::getPlaylistName() {
    return playlistName;
}