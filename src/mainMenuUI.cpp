#include <string>
#include <iostream>
#include "user.h"
#include "userInterface.h"
using namespace std;


void userInterface::displayMainMenu(){
int menuChoice=0;
User x;
cout<<"1)Library"<<endl;
cout<<"2)Playlist"<<endl;
cout<<"3)logout"<<endl;
cin>>menuChoice;
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
