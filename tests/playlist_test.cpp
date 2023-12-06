#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "playlist.h"
#include "library.h"
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

//DELETE SONG FUNCTION
//passing delete song function
TEST(PlaylistTests, passDeleteSong) {
    Playlist playlist;
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");

    playlist.addSong(newSong1);
    playlist.addSong(newSong2);
    playlist.addSong(newSong3);

    playlist.deleteSong(newSong1);
    playlist.deleteSong(newSong2);
    EXPECT_EQ(newSong3.getName(), playlist.at(0).getName());
}

//failing delete song function
TEST(PlaylistTests, failDeleteSong) {
    Playlist playlist;
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");

    playlist.addSong(newSong1);
    playlist.addSong(newSong2);
    playlist.addSong(newSong3);

    playlist.deleteSong(newSong1);
    playlist.deleteSong(newSong2);
    EXPECT_EQ(newSong1.getName(), playlist.at(2).getName());
    EXPECT_EQ(newSong2.getName(), playlist.at(1).getName());
}

//DELETE() FUNCTION
TEST(PlaylistTests, failDelete) {
    Playlist playlist;
    Song newSong1("No", "Meghan Trainor", "Pop");

    playlist.addSong(newSong1);

    playlist.deletePlaylist();
    
    EXPECT_TRUE(playlist.getPlaylistName().empty());
    EXPECT_TRUE(playlist.at(0).getName().empty());
    EXPECT_TRUE(playlist.at(0).getArtistName().empty());
    EXPECT_TRUE(playlist.at(0).getGenre().empty());

}

//SHAREPLAYLIST() FUNCTION
TEST(PlaylistTests, failSharePlaylistTest) {
    Playlist playlist;
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");
    playlist.addSong(newSong1);
    playlist.addSong(newSong2);
    playlist.addSong(newSong3);
    playlist.sharePlaylist();
    
    ifstream inputFile("playlist.txt");
    string line;
    vector<string> expectedLines = {"No, Meghan Trainor, Pop", "Tomboy, Destingy Rogers, Hip Hop", "Limbo, Keshi, R&B"};
    for (const auto& expectedLine : expectedLines) {
        getline(inputFile, line);
        EXPECT_EQ(line, expectedLine);
    }
    inputFile.close();
}

// RECOMMEND FUNCTION
TEST(PlaylistTests, failRecommend) {
    Playlist playlist;
    
    Song popSong("No", "Meghan Trainor", "Pop");
    Song hipHopSong("Tomboy", "Destingy Rogers", "Hip Hop");
    Song rAndBSong("Limbo", "Keshi", "R&B");

    Library library;
    library.addToLibrary(popSong);
    library.addToLibrary(hipHopSong);
    library.addToLibrary(rAndBSong);

    playlist.addSong(popSong);
    playlist.addSong(hipHopSong);
    playlist.addSong(rAndBSong);

    vector<Song> recommendedSongs = playlist.reccommend("Keshi", "Pop");

    // Ensure that the recommended songs vector contains the expected songs
    EXPECT_EQ(recommendedSongs.at(0).getName(), popSong.getName());
    EXPECT_EQ(recommendedSongs.at(1).getName(), rAndBSong.getName());
}
