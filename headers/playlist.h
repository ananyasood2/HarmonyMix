#include "song.h"
#include "db.h"
#include <string>
#include <vector>

using namespace std;

class Playlist {
private:
    vector<Song> songs;
    string playlistName;
public:
    Playlist() = default;
};