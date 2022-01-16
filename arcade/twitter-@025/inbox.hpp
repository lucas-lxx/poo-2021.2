#pragma once 
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <utility>
#include "tweet.hpp"
#include "../../cpp-functional/auxiliar.hpp"

class Inbox {
private:
    std::map<int, std::shared_ptr<Tweet>> all_tweets;
    std::map<int, std::shared_ptr<Tweet>> unread;

public:
    Inbox() {}

    std::map<int, std::shared_ptr<Tweet>> get_all() {
        return this->all_tweets;
    }

    std::shared_ptr<Tweet> get_tweet(int id) {
        auto it = all_tweets.find(id);
        if (it != all_tweets.end()) {
            return it->second;
        }
        throw std::runtime_error("fail: tweet not found!");
    }

    std::vector<Tweet> get_unread() {
        std::vector<Tweet> unread_copy;
        for (auto i : this->unread) {
            unread_copy.push_back(*i.second);
        }
        unread.clear();
        return unread_copy;
    }

    void new_tweet(std::shared_ptr<Tweet> tweet) {
        if (all_tweets.find(tweet->getId()) == all_tweets.end()) {
            all_tweets.insert({tweet->getId(), tweet});
            unread.insert({tweet->getId(), tweet});
            return;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Inbox inbox) {
        for (auto i : inbox.get_unread()) {
            os << i << '\n';
        }
        return os;
    }
};