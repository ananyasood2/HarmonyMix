#include <string>
#include <iostream>
#include "playlist.h"
#include "song.h"
#include "userInterface.h"
#include "user.h"
using namespace std;

void UI::displayPlaylistMenu(ostream &stream, istream &istream, User *user)
{
    int menuChoice = 0;
    stream << "1)Add Song" << endl;
    stream << "2)Delete Song" << endl;
    stream << "3)Create Playlist" << endl;
    stream << "4)List Playlists" << endl;
    stream << "5)Get Playlists's Songs" << endl;
    stream << "6)Back" << endl;
    istream >> menuChoice;
    while (menuChoice < 1 || menuChoice > 7)
    {
        stream << "Invalid input, try again: ";
        istream >> menuChoice;
    }
    
    if (menuChoice == 1)
    {
        istream.ignore(256, '\n');
        string playlistname, title, artist, genre;
        stream << "Enter the playlist name: ";
        getline(istream, playlistname);
        stream << "Enter the title of the song: ";
        getline(istream, title);
        stream << endl
               << "Enter the artist of the song: ";
        getline(istream, artist);
        stream << endl
               << "Enter the genre of the song: ";
        getline(istream, genre);
        user->addSongToPlaylist(playlistname, Song(title, artist, genre));
        displayPlaylistMenu(stream, istream, user);
    }
    else if (menuChoice == 2)
    {
        string playlistname, title, artist, genre;
        istream.ignore(256, '\n');
        stream << "Enter the playlist name: ";
        getline(istream, playlistname);
        stream << "Enter the title of the song: ";
        getline(istream, title);
        user->deleteSongFromPlaylist(playlistname, title);
        displayPlaylistMenu(stream, istream, user);
    }
    else if (menuChoice == 3)
    {
        string playlistname;
        istream.ignore(256, '\n');
        stream << "Enter the playlist name: ";
        getline(istream, playlistname);
        user->createPlaylist(playlistname);
        displayPlaylistMenu(stream, istream, user);
    }
    else if (menuChoice == 4)
    {
        auto playlists = user->get_playlists();
        for (auto playlist : playlists)
        {
            stream << playlist.getPlaylistName() << endl;
        }
        displayPlaylistMenu(stream, istream, user);
        
    }
    else if (menuChoice == 5)
    {
        string playlistname;
        istream.ignore(256, '\n');
        stream << "Enter the playlist name: ";
        getline(istream, playlistname);
        auto playlist = user->get_playlist(playlistname);
        for (auto song : playlist->getSongs())
        {
            song.displaySong(cout);
        }
    }
    else if (menuChoice == 4)
    {
        displayMainMenu(stream, istream, user);
    }
}