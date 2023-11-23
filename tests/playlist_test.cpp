#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "playlist.h"

//CONSTRUCTOR TESTS
//passing Constructor 
TEST(PlaylistTests, passConstructorTest){
    EXPECT_EQ(Playlist(playfulMix), "playfulMix");
}

//failing Constructor 
TEST(PlaylistTests, failConstructorTest){
    EXPECT_EQ(Playlist(playfulMix), "");
}

//ADD SONG FUNCTION
//passing add song function
TEST(PlaylistTests, passAddSong) {
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");

    EXPECT_EQ(addSong(newSong1), playlist.at(0));
    EXPECT_EQ(addSong(newSong2), playlist.at(1));
    EXPECT_EQ(addSong(newSong3), playlist.at(2));
}

//failing add song function
TEST(PlaylistTests, failAddSong) {
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");
    
    EXPECT_EQ(addSong(newSong1), playlist.at(2));
    EXPECT_EQ(addSong(newSong2), playlist.at(1));
    EXPECT_EQ(addSong(newSong3), playlist.at(0));
}

//DELTE SONG FUNCTION
//passing delete song function
TEST(PlaylistTests, passDeleteSong) {
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");

    EXPECT_NE(deleteSong(newSong1), playlist.at(0));
    EXPECT_NE(deleteSong(newSong2), playlist.at(1));
}

//failing delete song function
TEST(PlaylistTests, failDeleteSong) {
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");
    
    EXPECT_EQ(deleteSong(newSong1), playlist.at(2));
    EXPECT_EQ(deleteSong(newSong2), playlist.at(1));
}

int main(int argc, char **argv) {
    ::testing:InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

