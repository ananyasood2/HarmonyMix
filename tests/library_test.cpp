#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "library.cpp"

//CONSTRUCTOR TESTS
//expected to pass
TEST(LibraryTest, ConstructorTest){
    EXPECT_EQ(Library(testVector), testVector);
}

//SEARCH FUNCTION TESTS
//expected to pass
TEST(LibraryTest, SearchTest){
    Library *testLibrary = new Library();
    EXPECT_EQ(Library->searchBySongName(),"baby");
}

//expected to fail
TEST(LibraryTest, SearchTest){
    Library *testLibrary = new Library();
    EXPECT_EQ(Library->searchBySongName(),"no");
}