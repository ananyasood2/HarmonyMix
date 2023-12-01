#include <string>
#include <iostream>
#include "playlist.h"
#include "userInterface.h"
#include "library.h"
#include "user.h"
using namespace std;


void UI::displayLibraryMenu(){
int libraryChoice=0;
string songName, genre, artistName;
while(libraryChoice!=3){
cout<<"1)Add song"<<endl;
cout<<"2)Search"<<endl;
cout<<"3)Back to main menu";
cin>>libraryChoice;

if(libraryChoice==1){
    cout<<"enter the song name: ";
    cin>>songName;
    cout<<endl<<"Enter the artist name: ";
    cin>>artistName;
    cout<<endl<<"Enter the genre: ";
    cin>>genre;
    library.addToLibrary(songName, artistName, genre);
}

if(libraryChoice==2){
    int searchType=0;
    string name, genre1, songN;
    cout<<"1)Search by song name"<<endl;
    cout<<"2)Search by artist name "<<endl;
    cout<<"3)Search by genre "<<endl;
    cin>>libraryChoice;
    if(searchType==1){
        cout<<"Enter the song name: ";
        cin>>songN;
        library.searchBySongName(songN);
    }
    if(searchType==2){
        cout<<"Enter the artist name: ";
        cin>>name;
        library.searchByArtistName(name);
    }
    if(searchType==3){
        cout<<"Enter the genre: ";
        cin>>genre;
        library.searchByGenre(genre);
    }
}
}
if(libraryChoice==3){
    displayMainMenu();
}
}
