#pragma once
#include <iostream>
#include <map>
#include "inbox.hpp"


class User {
private:
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;
    std::shared_ptr<Inbox> inbox;
    std::string username;

    // adds tweet to the followers inboxes
    void store_tweet_followers(Tweet* tweet) {
        for (auto it : followers) {
            it.second->get_inbox()->new_tweet(tweet);
        }
    }

    void store_tweet_this_account(Tweet* tweet) {
        this->inbox->new_tweet(tweet);
    }

public:

    User(std::string username = ""): 
        username{username} {
        this->inbox = std::make_shared<Inbox>();
    }

    
    void follow(User* other) {
        auto it = other->followers.find(username);
        if (it == other->followers.end()) {
            other->followers.insert({username, this});
            this->following.insert({other->username, other});
            return;
        }
        throw std::runtime_error("fail: user not found");
    }

    void unfollow(std::string username) {
        auto it = following.find(username);
        if (it != following.end()) {
            it->second->followers.erase(it->second->followers.find(this->username));
            following.erase(it);
            return;
        }
        throw std::runtime_error("fail: user not found");
    }

    Inbox* get_inbox() {
        return this->inbox.get();
    }

    void like(int tweet_id) {
        inbox->get_tweet(tweet_id)->like(this->username);
    }

    void store_tweet(Tweet* tweet) {
        store_tweet_followers(tweet);
        store_tweet_this_account(tweet);
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
            if (count >= (int) user.followers.size()) {
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