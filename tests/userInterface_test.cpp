#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "userInterface.h"
#include "user.h"
#include <iostream>
#include <ostream>
#include <playlist.h>
#include <library.h>
#include <sstream>
#include <string>
void displayPlaylistMenu(std::ostream& stream){
    stream << "1) Create playlist"<<endl;
    stream << "2) AddSong" << endl;
    stream << "3) Delete Song" << endl;
}
void displayLibraryMenu(std::ostream& stream){
    stream << "1) AddSong" << endl;
    stream << "2) Search" << endl;
}

void displayLogin(std::ostream& stream){
    stream << "1) Create Account" << endl;
    stream << "2) Login" << endl;
}

void displayMainMenu(std::ostream& stream){
 stream<<"1) Library"<<endl;
 stream<<"2) Playlist"<<endl;
 stream<<"3) Logout"<<endl;
}



TEST(UITest, PlaylistUITest) {
User("Jordan", "pass");
std::ostringstream oss;
std::ostringstream test_oss;
test_oss << "1) Create playlist" << endl;

displayPlaylistMenu(oss);

EXPECT_EQ(oss.str(), "1) Create playlist\n2) AddSong\n3) Delete Song\n");
}


TEST(UITest, LibraryUITest) {
  Library lib;
  Song newSong("No", "Meghan Trainor", "Pop");

 lib.addToLibrary(newSong);
User("moooo", "pass");
std::ostringstream oss;
std::ostringstream test_oss;
test_oss << "1) AddSong" << endl;

displayLibraryMenu(oss);

EXPECT_EQ(oss.str(), "1) AddSong\n2) Search\n");
EXPECT_EQ(newSong.getName(), lib.at(0).getName());
}


TEST(UITest, LoginTest) {
User("moooo", "pass");
std::ostringstream oss;
std::ostringstream test_oss;
test_oss << "1) Create Account" << endl;

displayLogin(oss);

EXPECT_EQ(oss.str(), "1) Create Account\n2) Login\n");
}

TEST(UITest, MainMenuTest) {
User("moooo", "pass");
std::ostringstream oss;
std::ostringstream test_oss;
test_oss << "1) Playlist" << endl;

displayMainMenu(oss);

EXPECT_EQ(oss.str(), "1) Library\n2) Playlist\n3) Logout\n");
}
