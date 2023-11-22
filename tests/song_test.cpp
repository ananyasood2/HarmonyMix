#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "song.h"

//CONSTRUCTOR TESTS
//expected to pass
TEST(SongTest, ConstructorTest){
    Song *testSong = new Song("Baby", "Justin Beiber", "Pop");
    EXPECT_EQ (testSong->getName(), "Baby");
    EXPECT_EQ (testSong->getArtistName(), "Justin Beiber");
    EXPECT_EQ (testSong->getGenre(), "Pop");
}

//expected to pass (but is failing (BUG: case sensitive))
TEST(SongTest, FailConstructorTest){
    Song *testSong1 = new Song("Baby", "Justin Beiber", "Pop");
    EXPECT_EQ (testSong1->getName(), "baby");
    EXPECT_EQ (testSong1->getArtistName(), "justin beiber");
    EXPECT_EQ (testSong1->getGenre(), "pop");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return USER_ALL_TESTS();
}