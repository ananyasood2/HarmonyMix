#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "song.h"
#include "library.h"

//CONSTRUCTOR TESTS
//expected to pass
TEST(LibraryTest, ConstructorTest) {
    EXPECT_EQ(Library(testVector), testVector);
}

//SEARCH FUNCTION TESTS
//expected to pass
TEST(LibraryTest, testSearchBySongName1) {
    addSong("Baby", "Justin Beiber", "Pop");
    addSong("No", "Meghan Trainor", "Pop");
    addSong("Gernade", "Bruno Mars", "Pop");
    
    Library *testLibrary1 = new Library();
    EXPECT_EQ(Library->searchBySongName("Baby"),"Baby Justin Beiber Pop");
}

//expected to pass
TEST(LibraryTest, testSearchBySongName2) {
    addSong("Baby", "Justin Beiber", "Pop");
    addSong("No", "Meghan Trainor", "Pop");
    addSong("Gernade", "Bruno Mars", "Pop");
    
    Library *testLibrary2 = new Library();
    EXPECT_EQ(Library->searchBySongName("Gernade"),"Gernade Bruno Mars Pop");
}

//expected to pass
TEST(LibraryTest, testSearchByArtistName1) {
    addSong("Baby", "Justin Beiber", "Pop");
    addSong("No", "Meghan Trainor", "Pop");
    addSong("Gernade", "Bruno Mars", "Pop");
    
    Library *testLibrary3 = new Library();
    EXPECT_EQ(Library->searchByArtistName("Justin Beiber"),"Baby Justin Beiber Pop");
}

//expected to pass
TEST(LibraryTest, testSearchByArtistName2) {
    Library testLibrary;

    testlibrary.addToLibrary("Baby", "Justin Beiber", "Pop");
    testlibrary.addToLibrary("No", "Meghan Trainor", "Pop");
    testlibrary.addToLibrary("Gernade", "Bruno Mars", "Pop");

    EXPECT_EQ(testlibrary.searchByArtistName("Bruno Mars"), correctSon);
}

//SEARCHBYGENRE FUNCTION TESTS
//passing searchByGenre Tests 
TEST(LibraryTest, passSearchByGenre){
    addSong("Baby", "Justin Bieber", "Pop");
    addSong("No", "Meghan Trainor", "Pop");
    addSong("Gernade", "Bruno Mars", "Hip Hop");

    Library *testLibrary5 = new Library(); 
    EXPECT_EQ(Library->searchByGenre("Hip Hop"), "Gernade Bruno Mars Hip Hop");
}

//failing searchByGenre Tests 
TEST(LibraryTest, failSearchByGenre){
    addSong("Baby", "Justin Bieber", "Pop");
    addSong("No", "Meghan Trainor", "Pop");
    addSong("Gernade", "Bruno Mars", "Hip Hop");

    Library *testLibrary5 = new Library(); 
    EXPECT_EQ(Library->searchByGenre("Hip Hop"), "Baby Justin Bieber Pop");
}

//ADD SONG TO LIBRARY FUNCTION
//passing add song to libarayfunction
TEST(PlaylistTests, passAddToLibrarySong) {
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");

    EXPECT_EQ(addToLibrary(newSong1), songs.at(0));
    EXPECT_EQ(addToLibrary(newSong2), songs.at(1));
    EXPECT_EQ(addToLibrary(newSong3), songs.at(2));
}

//failing add song to libaray function
TEST(PlaylistTests, failAddToLibrarySong) {
    Song newSong1("No", "Meghan Trainor", "Pop");
    Song newSong2("Tomboy", "Destingy Rogers", "Hip Hop");
    Song newSong3("Limbo", "Keshi", "R&B");
    
    EXPECT_EQ(addToLibrary(newSong1), songs.at(2));
    EXPECT_EQ(addToLibrary(newSong2), songs.at(1));
    EXPECT_EQ(addToLibrary(newSong3), songs.at(0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}