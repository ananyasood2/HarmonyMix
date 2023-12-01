#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "playlist.h"

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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


// RECOMMEND FUNCTION
TEST(PlaylistTests, passRecommend) {
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

    vector<Song> recommendedSongs = playlist.recommend("Keshi", "Pop");

    // Ensure that the recommended songs vector contains the expected songs
    EXPECT_EQ(recommendedSongs.size(), 2);
    EXPECT_EQ(recommendedSongs[0].getName(), popSong.getName());
    EXPECT_EQ(recommendedSongs[1].getName(), rAndBSong.getName());
}

//failing recommend function
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

    vector<Song> recommendedSongs = playlist.recommend("Keshi", "Pop");

    // Introduce an intentional failure by expecting a different song
    EXPECT_EQ(recommendedSongs.size(), 2);
    EXPECT_EQ(recommendedSongs[0].getName(), hipHopSong.getName());
    EXPECT_EQ(recommendedSongs[1].getName(), rAndBSong.getName());
}