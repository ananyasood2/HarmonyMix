#include <string>
#include <iostream>
#include <vector>
#include "playlist.h"
#include "userInterface.h"
#include "library.h"
#include "user.h"
#include "song.h"
using namespace std;

void UI::displayLibraryMenu(ostream &stream, istream &istream, User *user)
{
    int libraryChoice = 0;
    string songName, genre, artistName;
    while (libraryChoice != 4)
    {
        cout << "1)Add song" << endl;
        cout << "2)Search" << endl;
        cout << "3)List songs" << endl;
        cout << "4)Back to main menu" << endl;
        istream >> libraryChoice;

        if (libraryChoice == 1)
        {
            istream.ignore(256, '\n');
            cout << "Enter the song name: ";
            getline(istream,songName);
            cout << endl
                 << "Enter the artist name: ";
            getline(istream,artistName);
            cout << endl
                 << "Enter the genre: ";
            getline(istream,genre);
            Song newSong(songName, artistName, genre);
            user->addSongToLibrary(newSong);
        }

        if (libraryChoice == 2)
        {
            int searchType = 0;
            string name, genre1, songN;
            cout << "1)Search by song name" << endl;
            cout << "2)Search by artist name " << endl;
            cout << "3)Search by genre " << endl;
            istream >> searchType;
            istream.ignore(256, '\n');
            if (searchType == 1)
            {

                cout << "Enter the song name: ";
                getline(istream, songN);
                vector<Song> result1 = user->get_library().searchBySongName(songN);
            }
            if (searchType == 2)
            {
                cout << "Enter the artist name: ";
                getline(istream, name);
                vector<Song> result2 = user->get_library().searchByArtistName(name);
            }
            if (searchType == 3)
            {
                cout << "Enter the genre: ";
                getline(istream, genre);
                vector<Song> result3 = user->get_library().searchByGenre(genre);
            }
            displayLibraryMenu(stream, istream, user);
        }
        if (libraryChoice == 3)
        {
            for (Song song : user->get_library().getSongs())
            {
                song.displaySong(stream);
            }
        }
        if (libraryChoice == 4)
        {
            displayMainMenu(stream, istream, user);
        }
    }
}
