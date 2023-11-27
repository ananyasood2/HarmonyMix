#include "playlist.h"


Playlist::Playlist {
    playlistName = "";
}

Playlist::Playlist(string playlist) {
    playlistName = playlist;
}

//adds the songName into the playlist vector  
void Playlist::addSong(Song &song) {
   playlist.push_back(songName);
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

vector<Song> Playlist::reccommend(string artistName, string genre) {
    Library libraryTest;
    vector<Song> genreRec;
    vector<Song> artistRec;

    genreRec = libraryTest.searchByGenre(genre);
    artistRec = libraryTest.searchByArtistName(artistName);

    genreRec.insert(genreRec.end(), artistRec.begin(), artistRec.end());

    return genreRec;
}