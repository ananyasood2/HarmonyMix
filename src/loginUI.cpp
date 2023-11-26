#include <string>
#include <iostream>
#include "userInterface.h"

using namespace std;


void UI::displayLogin(){
int login=0;
User x;
string userName, password;
cout<<"1)Login"<<endl;
cout<<"2)Create an Account"<<endl;
cin>>login;
if(login==1){
    cout<<"Enter your username: ";
    cin>>userName;
    cout<<endl<<"Enter your password: ";
    cin>>password;
    if(x.login(userName, password)){
        displayMainMenu();
    }
    else{
        cout<<"Wrong username or password."<<endl;
    }
}

}
