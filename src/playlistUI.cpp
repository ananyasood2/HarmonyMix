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

cout<<"1)Create a playlist"<<endl;
cout<<"2)Add song"<<endl;
cout<<"3)Delete song"<<endl;
cout<<"4)Display playlist"<<endl;
cout<<"5)Back to the main menu"<<endl;
cin>>playlistChoice;
if(playlistChoice==1){
    string playlistName;
    cout<<"Enter your playlist name: ";
    cin>>playlistName;
    cout<<endl;
    playlist=Playlist(playlistName);
}
if(playlistChoice==2){
    
    cout<<"Enter the song name: ";
    cin>>songName;
    cout<<endl<<"Enter the artist name: ";
    cin>>artistName;
    cout<<endl<<"Enter the genre: ";
    cin>>genre;
    Song newSong(songName, artistName, genre);
    playlist.addSong(newSong);
}
if(playlistChoice==3){
    cout<<"Enter the song name: ";
    cin>>songName;
    cout<<endl<<"Enter the artist name: ";
    cin>>artistName;
    cout<<endl<<"Enter the genre: ";
    cin>>genre;
    Song newSong(songName, artistName, genre);
    playlist.deleteSong(newSong);
}

if(playlistChoice==4){
    cout<<playlist.getPlaylistName()<<endl;
    playlist.displayPlaylist();
}
}
if(playlistChoice==5){
    displayMainMenu();
}

}