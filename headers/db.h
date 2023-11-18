#include "user.h"
#include <string>
#include <json/json.h>

class Db {
private:
    Json::Value db;
public:
    Db();
    void add_song_to_library(User *user);
    bool user_exists(std::string username);
};