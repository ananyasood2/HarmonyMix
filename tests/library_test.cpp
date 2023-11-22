#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "library.cpp"

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
    addSong("Baby", "Justin Beiber", "Pop");
    addSong("No", "Meghan Trainor", "Pop");
    addSong("Gernade", "Bruno Mars", "Pop");
    
    Library *testLibrary4 = new Library();
    EXPECT_EQ(Library->searchByArtistName("Bruno Mars"),"Gernade Bruno Mars Pop");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}