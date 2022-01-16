#pragma once
#include <iostream>
#include <map>
#include "user.hpp"
#include "tweet.hpp"
#include "inbox.hpp"

class Controller {
private:
    int nextTweetld;
    std::map<int, std::shared_ptr<Tweet>> tweets;
    std::map<std::string, std::shared_ptr<User>> users;

public:

    Controller() {
        this->nextTweetld = 0;
    }

    void add_user(std::string username) {
        auto user = std::make_shared<User>(username);
        auto it = users.find(username);
        if (it == users.end()) {
            users.insert({username, user});
            return;
        }
        throw std::runtime_error("fail: username unavailable");
    }

    void send_tweet(std::string username, std::string tweet_text) {

    }

    std::shared_ptr<User> get_user(std::string username) {
        auto found { users.find(username) };
        if (found == users.end())
            throw std::runtime_error("fail: user not found");
        return found->second;
    }
    
};