#pragma once
#include <iostream>
#include <map>
#include "inbox.hpp"


class User {
private:
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;
    Inbox* inbox;
    std::string username;

public:

    User(std::string username = ""): 
        username{username} {
        this->inbox = nullptr;
    }

    void follow(User& other) {
        if (other.followers.find(username) == other.followers.end()) {
            other.followers[username] = this;
            this->following[other.username] = &other;
        }
        throw std::runtime_error("fail: user not found");
    }


    
};