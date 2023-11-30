#include <string>
#include <iostream>
#include "playlist.h"
#include "song.h"
#include "userInterface.h"
#include "user.h"
using namespace std;


void UI::displayPlaylistMenu(){
int playlistChoice=0;
string songName, genre, artistName;
while(playlistChoice!=5){


cout<<"1)Add song"<<endl;
cout<<"2)Delete song"<<endl;
cout<<"3)Create a playlist"<<endl;
cout<<"4)Display playlist"<<endl;
cout<<"5)Back to the main menu"<<endl;
cin>>playlistChoice;

if(playlistChoice==1){
    
    cout<<"enter the song name: ";
    cin>>songName;
    cout<<endl<<"Enter the artist name: ";
    cin>>artistName;
    cout<<endl<<"Enter the genre: ";
    cin>>genre;
     Song newSong(songName, artistName, genre);
    playlists.addSong(newSong);
}
if(playlistChoice==2){
    cout<<"enter the song name: ";
    cin>>songName;
    cout<<endl<<"Enter the artist name: ";
    cin>>artistName;
    cout<<endl<<"Enter the genre: ";
    cin>>genre;
    Song newSong(songName, artistName, genre);
    playlists.deleteSong(newSong);
}
if(playlistChoice==3){
    string playlistName;
    cout<<"Enter your playlist name: ";
    cin>>playlistName;
    cout<<endl;
    playlists.Playlist(playlistName);
}
if(playlistChoice==4){
    cout<<playlists.getPlaylistName()<<endl;
    playlists.displayPlaylist();
}
}
if(playlistChoice==5){
    displayMainMenu();
}

}