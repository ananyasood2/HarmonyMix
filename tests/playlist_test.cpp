#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "playlist.h"

//CONSTRUCTOR TESTS
//passing Constructor 
TEST(PlaylistTests, passConstructorTest){
    // EXPECT_EQ(Playlist("playfulMix"), "playfulMix");
}

//failing Constructor 
TEST(PlaylistTests, failConstructorTest){
    // EXPECT_EQ(Playlist("playfulMix"), "");
}

//ADD SONG FUNCTION
//passing add song function
TEST(PlaylistTests, passAddSong) {
    Playlist playlist;
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");
    
    playlist.addSong(newSong1);
    playlist.addSong(newSong2);
    playlist.addSong(newSong3);

    EXPECT_EQ(newSong1, playlist.at(0));
    EXPECT_EQ(newSong2, playlist.at(1));
    EXPECT_EQ(newSong3, playlist.at(2));
}

//failing add song function
TEST(PlaylistTests, failAddSong) {
    Playlist playlist;
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");
    playlist.addSong(newSong1);
    playlist.addSong(newSong2);
    playlist.addSong(newSong3);
    EXPECT_EQ(newSong1, playlist.at(2));
    EXPECT_EQ(newSong2, playlist.at(0));
    EXPECT_EQ(newSong3, playlist.at(1));
}

//DELTE SONG FUNCTION
//passing delete song function
TEST(PlaylistTests, passDeleteSong) {
    Playlist playlist;
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");
    playlist.deleteSong(newSong1);
    playlist.deleteSong(newSong2);
    EXPECT_NE(newSong1, playlist.at(0));
    EXPECT_NE(newSong2, playlist.at(1));
}

//failing delete song function
TEST(PlaylistTests, failDeleteSong) {
    Playlist playlist;
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");
    playlist.deleteSong(newSong1);
    playlist.deleteSong(newSong2);
    EXPECT_EQ(newSong1, playlist.at(2));
    EXPECT_EQ(newSong2, playlist.at(1));
}

// int main(int argc, char **argv) {
//     ::testing:InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

