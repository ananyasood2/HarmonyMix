#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "userInterface.h"
#include "user.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
void displayPlaylistMenu(std::ostream& stream){
    stream << "1) AddSong" << endl;
    stream << " 2) Delete Song" << endl;
}
void displayLibraryMenu(std::ostream& stream){
    stream << "1) AddSong" << endl;
    stream << " 2) Delete Song" << endl;
}


TEST(mainMenuTest, Test1) {
User("Jordan", "pass");
std::ostringstream oss;
std::ostringstream test_oss;
test_oss << "1) AddSong" << endl;

displayPlaylistMenu(oss);

EXPECT_EQ(oss.str(), "1) AddSong\n 2) Delete Song\n");
}


TEST(mainMenuTest, Test2) {
User("moooo", "pass");
std::ostringstream oss;
std::ostringstream test_oss;
test_oss << "1) AddSong" << endl;

displayLibraryMenu(oss);

EXPECT_EQ(oss.str(), "1) AddSong\n 2) Delete Song\n");
}

