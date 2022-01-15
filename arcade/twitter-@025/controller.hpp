#pragma once
#include <iostream>
#include <map>
#include "user.hpp"
#include "tweet.hpp"
#include "inbox.hpp"

class Controller {
private:
    int nextTwld;
    std::map<int, Tweet> tweets;
    std::map<std::string, User*> users;

public:

    User* get_user(std::string username) {
        auto found { users.find(username) };
        if (found == users.end())
            throw std::runtime_error("fail: user not found");
        return found->second;
    }
    
};