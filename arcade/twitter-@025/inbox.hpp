#pragma once 
#include <iostream>
#include <map>
#include <sstream>
#include "tweet.hpp"

class Inbox {
private:
    std::map<int, Tweet> all_tweets;
    std::map<int, Tweet*> unread;

public:
    Inbox() {}

    std::map<int, Tweet> get_all() {
        return this->all_tweets;
    }

    Tweet get_tweet(int id) {
        return all_tweets.find(id)->second;
    }

    std::map<int, Tweet*> get_unread() {
        return unread;
    }
};