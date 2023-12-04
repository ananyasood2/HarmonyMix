#include <string>
#include <iostream>
#include "userInterface.h"

using namespace std;


void UI::displayLogin(){
int loginChoice=0;

string userName, password;
cout<<"1)Create an Account"<<endl;
cout<<"2)Login"<<endl;
cin>>loginChoice;
if(loginChoice==1){
string userr, pass;
cout<<"Enter your desired user name: ";
cin>>userr;
cout<<endl<<"Enter your desired password: ";
cin>>pass;
user= User(userr, pass);
displayMainMenu();
}
if(loginChoice==2){
    cout<<"Enter your username: ";
    cin>>userName;
    cout<<endl<<"Enter your password: ";
    cin>>password;
    if(user.login(userName, password)==true){
        displayMainMenu();
    }
    else{
        cout<<"Wrong username or password, exiting."<<endl;
        exit(0);
    }
}
}


