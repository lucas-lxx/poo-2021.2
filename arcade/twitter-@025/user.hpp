#pragma once
#include <iostream>
#include <map>
#include "inbox.hpp"


class User : public std::enable_shared_from_this<User> {
private:
    std::map<std::string, std::shared_ptr<User>> followers;
    std::map<std::string, std::shared_ptr<User>> following;
    std::shared_ptr<Inbox> inbox;
    std::string username;

public:

    User(std::string username = ""): 
        username{username} {
        this->inbox = nullptr;
    }

    
    void follow(std::shared_ptr<User> other) {
        auto it = other->followers.find(username);
        if (it == other->followers.end()) {
            other->followers[username] = shared_from_this();
            this->following[other->username] = other;
            return;
        }
        throw std::runtime_error("fail: user not found");
    }

    std::shared_ptr<Inbox> get_inbox() {
        return this->inbox;
    }

    friend std::ostream& operator<<(std::ostream& os, User user) {
        os << user.username << '\n';
        os << " following [";
        int count {1};
        for (auto i : user.following) {
            if (count >= (int) user.following.size()) {
                os << i.second->username;
                count = 1;
                break;
            }
            os << i.second->username << ", ";
            count++;
        }
        os << "]\n";

        os << " followers [";
        for (auto i : user.followers) {
            if (count >= (int) user.following.size()) {
                os << i.second->username;
                break;
            }
            os << i.second->username << ", ";
            count++;
        }
        os << "]\n";
        return os;
    }
    
};