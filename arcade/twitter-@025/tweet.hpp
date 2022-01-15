#pragma once
#include <iostream>
#include <map>
#include <set>

class Tweet {
private:
    int id;
    std::set<std::string> likes;
    std::string username;
    std::string msg;

public:

    Tweet(int id = -1, std::string username = "", std::string msg = ""): 
        id{id}, username{username}, msg{msg} {
    }

    void like(std::string username) {
        if (likes.find(username) == likes.end())
            likes.insert(username);
        throw std::runtime_error("fail: already liked");
    }

};