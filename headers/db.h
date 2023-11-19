#ifndef DB_H
#define DB_H
#include <string>
#include "json/json.h"

class Db {
private:
    Json::Value db;
public:
    Db();
    void add_song_to_library(std::string username);
    bool user_exists(std::string username);
};

#endif