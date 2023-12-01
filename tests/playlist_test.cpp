#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "playlist.h"
#include <vector>
#include <string>
#include <fstream>

//CONSTRUCTOR TESTS
//passing Constructor 
TEST(PlaylistTests, passConstructorTest){
    Playlist playlist("playfulMix");
    EXPECT_EQ(playlist.getPlaylistName(), "playfulMix");
}

//failing Constructor 
TEST(PlaylistTests, failConstructorTest){
    Playlist playlist("playfulMix");
    EXPECT_EQ(playlist.getPlaylistName(), "");
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

    EXPECT_EQ(newSong1.getName(), playlist.at(0).getName());
    EXPECT_EQ(newSong2.getName(), playlist.at(1).getName());
    EXPECT_EQ(newSong3.getName(), playlist.at(2).getName());
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

    EXPECT_EQ(newSong1.getName(), playlist.at(2).getName());
    EXPECT_EQ(newSong2.getName(), playlist.at(1).getName());
    EXPECT_EQ(newSong3.getName(), playlist.at(0).getName());
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

    EXPECT_EQ(newSong1.getName(), playlist.at(0).getName());
    EXPECT_EQ(newSong2.getName(), playlist.at(1).getName());
}

//failing delete song function
TEST(PlaylistTests, failDeleteSong) {
    Playlist playlist;

    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");

    playlist.deleteSong(newSong1);
    playlist.deleteSong(newSong2);
    
    EXPECT_EQ(newSong1.getName(), playlist.at(2).getName());
    EXPECT_EQ(newSong2.getName(), playlist.at(1).getName());
}

TEST(PlaylistTests, passDelete) {
    Playlist playlist;

    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");

    playlist.addSong(newSong1);
    playlist.addSong(newSong2);
    playlist.addSong(newSong3);

    playlist.deletePlaylist();

    EXPECT_TRUE(playlist.getPlaylistName().empty());
    EXPECT_TRUE(playlist.at(0).getName().empty());
    EXPECT_TRUE(playlist.at(1).getName().empty());
    EXPECT_TRUE(playlist.at(2).getName().empty());
}

TEST(PlaylistTests, SharePlaylistTest) {
    Playlist playlist;

    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");

    playlist.addSong(newSong1);
    playlist.addSong(newSong2);
    playlist.addSong(newSong3);

    ofstream outputFile = playlist.sharePlaylist();
    outputFile.close();

    ifstream inputFile("playlist.txt");
    string line;
    vector<string> expectedLines = {"No, Meghan Trainor, Pop", "Tomboy, Destingy Rogers, Hip Hop", "Limbo, Keshi, R&B"};
    
    for (const auto& expectedLine : expectedLines) {
        getline(inputFile, line);
        EXPECT_EQ(line, expectedLine);
    }
    inputFile.close();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

