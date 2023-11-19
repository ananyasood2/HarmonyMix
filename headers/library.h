#include "song.h"
#include "db.h"

using namespace std;

class Library {
    private:
        vector<Song> songs;
    public:
        Library() = default;
        Song searchBySongName(string songName);
        Song searchByArtistName(string artistName); 
        Song searchByGenre(string genreName);
};