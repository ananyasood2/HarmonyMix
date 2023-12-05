#include <string>
#include <iostream>
#include <ostream>
#include "user.h"
#include "userInterface.h"
using namespace std;
void UI::displayPlaylistMenu(ostream &stream, User *user)
{
    int menuChoice = 0;
    stream << "1)Add Song" << endl;
    stream << "2)Delete Song" << endl;
    stream << "3)Create Playlist" << endl;
    stream << "4)List Playlists" << endl;
    stream << "5)Get Playlists's Songs" << endl;
    stream << "6)Back" << endl;
    cin >> menuChoice;
    while (menuChoice < 1 || menuChoice > 4)
    {
        stream << "Invalid input, try again: ";
        cin >> menuChoice;        
    }
    cin.ignore(256, '\n');
    if (menuChoice == 1)
    {
        string playlistname, title, artist, genre;
        stream << "Enter the playlist name: ";
        getline(cin, playlistname);
        stream << "Enter the title of the song: ";
        getline(cin, title);
        stream << endl
             << "Enter the artist of the song: ";
        getline(cin, artist);
        stream << endl
             << "Enter the genre of the song: ";
        getline(cin, genre);
        user->addSongToPlaylist(Playlist(playlistname), Song(title, artist, genre));
    }
    else if (menuChoice == 2)
    {
        string playlistname, title, artist, genre;
        cin.ignore(256, '\n');
        stream << "Enter the playlist name: ";
        getline(cin, playlistname);
        stream << "Enter the title of the song: ";
        getline(cin, title);
        user->deleteSongFromPlaylist(playlistname, title);
    }
    else if (menuChoice == 3)
    {
        string playlistname;
        cin.ignore(256, '\n');
        stream << "Enter the playlist name: ";
        getline(cin, playlistname);
        user->createPlaylist(playlistname);
    }
    else if (menuChoice == 4)
    {
        auto playlists = user->get_playlists();
        for (auto playlist : playlists)
        {
            stream << playlist.getPlaylistName() << endl;
        }
    }
    else if (menuChoice == 5)
    {
        string playlistname;
        cin.ignore(256, '\n');
        stream << "Enter the playlist name: ";
        getline(cin, playlistname);
        auto playlist = user->get_playlist(playlistname);
        for (auto song : playlist.getSongs())
        {
            song.displaySong(cout);
        }
    }
    else if (menuChoice == 4)
    {
        displayMainMenu(stream, user);
    }
}
void UI::displayLibraryMenu(ostream &stream, User *user) {
    int menuChoice = 0;
    stream << "1)Add Song" << endl;
    stream << "2)Delete Song" << endl;
    stream << "3)List Songs" << endl;
    stream << "4)Back" << endl;
    cin >> menuChoice;
    while (menuChoice < 1 || menuChoice > 4)
    {
        stream << "Invalid input, try again: ";
        cin >> menuChoice;        
    }
    cin.ignore(256, '\n');
    if (menuChoice == 1)
    {
        string title, artist, genre;
        stream << "Enter the title of the song: ";
        getline(cin, title);
        stream << endl
             << "Enter the artist of the song: ";
        getline(cin, artist);
        stream << endl
             << "Enter the genre of the song: ";
        getline(cin, genre);
        user->addSongToLibrary(Song(title, artist, genre));
    }
    else if (menuChoice == 2)
    {
        string title, artist, genre;
        cin.ignore(256, '\n');
        stream << "Enter the title of the song: ";
        getline(cin, title);
        user->deleteSongFromLibrary(title);
    }
    else if (menuChoice == 3)
    {
        auto library = user->get_library();
        for (auto song : library)
        {
            song.displaySong(cout);
        }
    }
    else if (menuChoice == 4)
    {
        displayMainMenu(stream, user);
    }
    
    
    
}
void UI::displayMainMenu(ostream &stream, User *user)
{
    int menuChoice = 0;
    stream << "1)Library" << endl;
    stream << "2)Playlist" << endl;
    stream << "3)logout" << endl;
    cin >> menuChoice;
    while (menuChoice < 1 || menuChoice > 3)
    {
        cout << "Invalid input, try again: ";
        cin >> menuChoice;
    }

    if (menuChoice == 1)
    {
        this->displayLibraryMenu(stream, user);        
    }
    if (menuChoice == 2)
    {
        this->displayPlaylistMenu(stream, user);
    }
    if (menuChoice == 3)
    {
        user->logout();
    }
}

