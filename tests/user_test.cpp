#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "user.h"
#include <string>
using namespace std;
User user;
Song song("test name", "test artist", "test genre");
Playlist playlist("test playlist");
TEST(UserTests, LoginTest){
    EXPECT_TRUE(user.login("jordan", "test"));
}

TEST(UserTests, LogoutTest){
    User _user(user);
    EXPECT_TRUE(_user.logout());
}

TEST(UserTests, GetUsernameTest){
    User user;
    user.login("jordan", "test");
    EXPECT_EQ(user.get_username(), "jordan");
}

TEST(UserTests, GetPasswordTest){
    std::hash<string> str_hash;
// EXPECT_EQ(user.get_password(), std::string(str_hash("test")));
}

TEST(UserTests, GetLibraryTest){
    EXPECT_EQ(user.get_library().getSongs().size(), 2);
}

TEST(UserTests, GetPlaylistsTest){
    EXPECT_EQ(user.get_playlists().size(), 1);
}

TEST(UserTests, CreatePlaylistTest){
    user.createPlaylist("test playlist");
    EXPECT_EQ(user.get_playlists().size(), 1);
}

TEST(UserTests, GetPlaylistTest){
    EXPECT_EQ(user.get_playlist("test playlist")->getPlaylistName(), "test playlist");
}

TEST(UserTests, AddSongToPlaylistTest){    
    user.addSongToPlaylist(playlist.getPlaylistName(), song);
    EXPECT_EQ(user.get_playlist("test playlist")->getSongs().size(), 1);
}

TEST(UserTests, DeleteSongFromPlaylistTest){
    user.deleteSongFromPlaylist(playlist.getPlaylistName(), song.getName());
    EXPECT_EQ(user.get_playlist("test playlist")->getSongs().size(), 0);
}

TEST(UserTests, AddSongToLibraryTest){
    user.addSongToLibrary(song);
    EXPECT_EQ(user.get_library().getSongs().size(), 3);
}

TEST(UserTests, DeleteSongFromLibraryTest){
    user.deleteSongFromLibrary(song.getName());
    EXPECT_EQ(user.get_library().getSongs().size(), 2);
}