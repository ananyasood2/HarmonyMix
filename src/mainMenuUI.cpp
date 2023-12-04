#include <string>
#include <iostream>
#include "user.h"
#include "userInterface.h"
using namespace std;


void UI::displayMainMenu(){
int menuChoice=0;
cout<<"1)Playlist"<<endl;
cout<<"2)Library"<<endl;
cout<<"3)logout"<<endl;
cin>>menuChoice;
while (menuChoice<1 || menuChoice>3)
{
    cout<<"Invalid input, try again: ";
    cin>>menuChoice;
}

if(menuChoice==1){
    displayPlaylistMenu();
}
if(menuChoice==2){
    displayLibraryMenu();
}
if(menuChoice==3){
    user.logout();
}
}
