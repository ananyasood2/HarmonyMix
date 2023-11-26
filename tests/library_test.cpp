#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "song.h"
#include "library.h"

//SEARCH FUNCTION TESTS
//expected to pass
TEST(LibraryTest, testSearchBySongName1) {
    Library testLibrary1;

    Song newSong1("Baby", "Justin Beiber", "Pop");
    Song newSong2("No", "Meghan Trainor", "Pop");
    Song newSong3("Gernade", "Bruno Mars", "Hip Hop");

    testLibrary1.addToLibrary(newSong1);
    testLibrary1.addToLibrary(newSong2);
    testLibrary1.addToLibrary(newSong3);

    vector<Song> expectedSongs;
    expectedSongs.push_back(Song("Baby", "Justin Beiber", "Pop"));

    // Search for songs with the name "Baby"
    vector<Song> resultSongs = testLibrary1.searchBySongName("Baby");

    // Compare the result with the expected value
    EXPECT_EQ(resultSongs, expectedSongs);
}

//expected to pass
TEST(LibraryTest, testSearchBySongName2) {
    Library testLibrary2;

    Song newSong1("Baby", "Justin Beiber", "Pop");
    Song newSong2("No", "Meghan Trainor", "Pop");
    Song newSong3("Gernade", "Bruno Mars", "Hip Hop");

    testLibrary2.addToLibrary(newSong1);
    testLibrary2.addToLibrary(newSong2);
    testLibrary2.addToLibrary(newSong3);

    vector<Song> expectedSongs;
    expectedSongs.push_back(Song("Gernade", "Bruno Mars", "Hip Hop"));

    // Search for songs with the name "Gernade"
    vector<Song> resultSongs = testLibrary2.searchBySongName("Gernade");

    // Compare the result with the expected value
    EXPECT_EQ(resultSongs, expectedSongs);
}

//expected to pass
TEST(LibraryTest, testSearchByArtistName1) {
    Library testLibrary3;

    Song newSong1("Baby", "Justin Beiber", "Pop");
    Song newSong2("No", "Meghan Trainor", "Pop");
    Song newSong3("Gernade", "Bruno Mars", "Hip Hop");

    testLibrary3.addToLibrary(newSong1);
    testLibrary3.addToLibrary(newSong2);
    testLibrary3.addToLibrary(newSong3);

    vector<Song> expectedSongs;
    expectedSongs.push_back(Song("Baby", "Justin Beiber", "Pop"));

    // Search for songs with the artist "Justin Beiber"
    vector<Song> resultSongs = testLibrary3.searchByArtistName("Justin Beiber");

    // Compare the result with the expected value
    EXPECT_EQ(resultSongs, expectedSongs);
}

//expected to pass
TEST(LibraryTest, testSearchByArtistName2) {
    Library testLibrary4;

    Song newSong1("Baby", "Justin Beiber", "Pop");
    Song newSong2("No", "Meghan Trainor", "Pop");
    Song newSong3("Gernade", "Bruno Mars", "Hip Hop");

    testLibrary4.addToLibrary(newSong1);
    testLibrary4.addToLibrary(newSong2);
    testLibrary4.addToLibrary(newSong3);

    vector<Song> expectedSongs;
    expectedSongs.push_back(Song("Gernade", "Bruno Mars", "Hip Hop"));

    // Search for songs with the artist "Bruno Mars"
    vector<Song> resultSongs = testLibrary4.searchByArtistName("Bruno Mars");

    // Compare the result with the expected value
    EXPECT_EQ(resultSongs, expectedSongs);
}

//SEARCHBYGENRE FUNCTION TESTS
//passing searchByGenre Tests 
TEST(LibraryTest, passSearchByGenre){
    Library testLibrary5;

    Song newSong1("Baby", "Justin Beiber", "Pop");
    Song newSong2("No", "Meghan Trainor", "Pop");
    Song newSong3("Gernade", "Bruno Mars", "Hip Hop");

    testLibrary5.addToLibrary(newSong1);
    testLibrary5.addToLibrary(newSong2);
    testLibrary5.addToLibrary(newSong3);

    vector<Song> expectedSongs;
    expectedSongs.push_back(Song("Gernade", "Bruno Mars", "Hip Hop"));

    // Search for songs with the genre "Hip Hop"
    vector<Song> resultSongs = testLibrary5.searchByGenre("Hip Hop");

    // Compare the result with the expected value
    EXPECT_EQ(resultSongs, expectedSongs);
}

//failing searchByGenre Tests 
TEST(LibraryTest, failSearchByGenre){
    Library testLibrary6;

    Song newSong1("Baby", "Justin Beiber", "Pop");
    Song newSong2("No", "Meghan Trainor", "Pop");
    Song newSong3("Gernade", "Bruno Mars", "Hip Hop");

    testLibrary6.addToLibrary(newSong1);
    testLibrary6.addToLibrary(newSong2);
    testLibrary6.addToLibrary(newSong3);

    vector<Song> expectedSongs;
    expectedSongs.push_back(Song("Baby", "Justin Bieber", "Pop"));

    // Search for songs with the genre "Hip Hip"
    vector<Song> resultSongs = testLibrary6.searchByGenre("Hip Hop");

    // Compare the result with the expected value
    EXPECT_EQ(resultSongs, expectedSongs);
}

//ADD SONG TO LIBRARY FUNCTION
//passing add song to library function
TEST(LibraryTest, passAddToLibrarySong) {
    Library testLibrary7;

    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");

    testLibrary7.addToLibrary(newSong1);
    testLibrary7.addToLibrary(newSong2);
    testLibrary7.addToLibrary(newSong3);

    EXPECT_EQ(newSong1, testLibrary7.at(0));
    EXPECT_EQ(newSong2, testLibrary7.at(1));
    EXPECT_EQ(newSong3, testLibrary7.at(2));
}

//failing add song to library function
TEST(LibraryTest, failAddToLibrarySong) {
    Library testLibrary8;

    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");

    testLibrary8.addToLibrary(newSong1);
    testLibrary8.addToLibrary(newSong2);
    testLibrary8.addToLibrary(newSong3);
    
    EXPECT_EQ(newSong1, testLibrary8.at(2));
    EXPECT_EQ(newSong2, testLibrary8.at(1));
    EXPECT_EQ(newSong3, testLibrary8.at(0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}