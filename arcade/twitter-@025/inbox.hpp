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

    std::vector<Tweet> to_vector(auto all_tweets) {
        std::vector<Tweet> vec;
        for (auto i : all_tweets) {
            vec.push_back(*i.second);
        }
        return vec;
    }

public:
    Inbox() {}

    // retunrs all the tweets on the inbox
    std::vector<Tweet> get_all() {
        this->unread.clear();
        return to_vector(this->all_tweets);
    }

    // returns a tweet by it's id adressed on the map
    std::shared_ptr<Tweet> get_tweet(int id) {
        auto it = all_tweets.find(id);
        if (it != all_tweets.end()) {
            return it->second;
        }
        throw std::runtime_error("fail: tweet not found!");
    }

    // returns a vector of the unread tweets
    std::vector<Tweet> get_unread() {
        std::vector<Tweet> unread_copy = to_vector(this->unread);
        unread.clear();
        return unread_copy;
    }

    // adds a new tweet to the inbox
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