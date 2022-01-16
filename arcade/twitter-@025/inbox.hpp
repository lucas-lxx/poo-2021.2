#pragma once 
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "tweet.hpp"
#include "../../cpp-functional/auxiliar.hpp"

class Inbox {
private:
    std::vector<std::shared_ptr<Tweet>> all_tweets;
    int first_unread;
    bool read;

public:
    Inbox() {
        this->first_unread = 0;
        this->read = false;
    }

    std::vector<std::shared_ptr<Tweet>> get_all() {
        return this->all_tweets;
    }

    Tweet get_tweet(int id) {
        return all_tweets[id]->getId();
    }

    std::vector<std::shared_ptr<Tweet>> get_unread() {
        static std::vector<std::shared_ptr<Tweet>> unreaded_tweets;
        if (!read) {
            unreaded_tweets.clear();
            unreaded_tweets = aux::slice(all_tweets, first_unread);
            first_unread = all_tweets.size();
        }
        return unreaded_tweets;
    }

    void new_tweet(std::shared_ptr<Tweet> tweet) {
        all_tweets.push_back(tweet);
    }

    friend std::ostream& operator<<(std::ostream& os, Inbox inbox) {
        for (auto i : inbox.get_unread()) {
            os << *i << '\n';
        }
        return os;
    }
};