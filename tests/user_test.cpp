#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "user.h"
TEST(UserTests, LoginTest){
    User user("", "");
    EXPECT_FALSE(user.login("test", "test"));

}

TEST(UserTests, LogoutTest){
    User user("test", "test");
    EXPECT_FALSE(user.logout());
}