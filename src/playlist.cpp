#include "playlist.h"

PlayList::Playlist {
    playlistName = 0;
}

//adds the songName into the playlist vector  
void Playlist::addSong(Song &song) {
   playlist.push_back(songName);
}

//deletes a song from the playlist vector 
void PlayList::deleteSong(Song &song) {
    for (auto iterate = playlist.begin(); iterate != playlist.end(); ++iterate) {
        if (iterate->getName() == song.getName()) {
            iterate = playlist.erase(iterate);
            --iterate; 
        }
    }
    
}

for (Song &song : playlist) {
        if (song.getName() == songName) {
            songs.erase()
        }
    }