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
    std::map<int, Tweet*> all_tweets;
    std::map<int, Tweet*> unread;

    std::vector<Tweet> to_vector(std::map<int, Tweet*> all_tweets) {
        std::vector<Tweet> vec;
        for (auto i : all_tweets) {
            vec.push_back(*i.second);
        }
        return vec;
    }

    std::vector<int> get_user_tweets(std::string username) {
        std::vector<int> to_remove;
        for (const auto& i : all_tweets) {
            if (i.second->get_sender() == username) 
                to_remove.push_back(i.first);
        }
        return to_remove;
    }

    void rm_tweets_by_ids(std::vector<int> ids, std::map<int, Tweet*> map) {
        for (const auto& i : ids)
            map.erase(i);
    }

public:
    Inbox() {}

    // retunrs all the tweets on the inbox
    std::map<int, Tweet*> get_all() {
        this->unread.clear();
        return this->all_tweets;
    }

    // returns a tweet by it's id adressed on the map
    Tweet* get_tweet(int id) {
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
    void new_tweet(Tweet* tweet) {
        if (all_tweets.find(tweet->getId()) == all_tweets.end()) {
            all_tweets.insert({tweet->getId(), tweet});
            unread.insert({tweet->getId(), tweet});
            return;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Inbox inbox) {
        for (const auto& it : inbox.get_all()) {
            os << *it.second << '\n';
        }
        return os;
    }
};