#pragma once
#include <iostream>
#include <map>
#include <memory>
#include "user.hpp"
#include "tweet.hpp"
#include "inbox.hpp"

class Controller {
private:
    int next_tweet_id;
    std::map<int, std::shared_ptr<Tweet>> tweets;
    std::map<std::string, std::shared_ptr<User>> users;

    Tweet* create_tweet(std::string username, std::string tweet_text) {
        auto tweet = std::make_shared<Tweet>(next_tweet_id, username, tweet_text);
        tweets.insert({next_tweet_id, tweet});
        next_tweet_id++;
        return tweet.get();
    }

public:

    Controller() {
        this->next_tweet_id = 0;
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
        auto user = get_user(username);
        auto tweet = create_tweet(username, tweet_text);
        user->store_tweet(tweet);
    }

    User* get_user(std::string username) {
        auto found = users.find(username);
        if (found == users.end())
            throw std::runtime_error("fail: user not found");
        return found->second.get();
    }

    void send_retweet(std::string username, int retweet_id, std::string tweet_text) {
        auto user = get_user(username);
        auto retweet = user->get_inbox()->get_tweet(retweet_id);
        auto tweet = create_tweet(username, tweet_text);
        tweet->set_retweet(retweet);
        user->store_tweet(tweet);
    }
    
    friend std::ostream& operator<<(std::ostream& os, Controller controller) {
        for (auto it : controller.users) {
            os << *it.second;
        }
        return os;
    }
};