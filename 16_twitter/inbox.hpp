#pragma once 
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <utility>
#include "tweet.hpp"
#include "cpp-functional/auxiliar.hpp"
#include "exception"

class Inbox {
private:
    std::map<int, Tweet*> all_tweets;
    std::map<int, Tweet*> my_tweets;

    // returns a vector with the all the keys to the user
    std::vector<int> get_user_tweets(std::string user_name, std::map<int, Tweet*>& map) {
        std::vector<int> to_remove;
        for (const auto& i : map) {
            if (i.second->get_sender() == user_name) 
                to_remove.push_back(i.first);
        }
        return to_remove;
    }

    void rm_tweets_by_ids(std::vector<int> ids, std::map<int, Tweet*>& map) {
        for (const auto& i : ids)
            map.erase(i);
    }

    std::vector<Tweet*> to_vector(std::map <int, Tweet*> map) {
        std::vector<Tweet*> vec;
        for (const auto& i : map) 
            vec.push_back(i.second);
        return vec;
    }

public:
    Inbox() {}

    // removes all the tweets from the user, by it's username
    void rm_tweets_from(std::string username) {
        auto to_remove = get_user_tweets(username, this->all_tweets);
        rm_tweets_by_ids(to_remove, this->all_tweets);
    }

    // returns a tweet by it's id adressed on the map
    Tweet* get_tweet(int id) {
        auto it = all_tweets.find(id);
        if (it != all_tweets.end()) {
            return it->second;
        }
        throw TweetException("fail: tweet not found!");
    }

    // adds a new tweet to the inbox
    void store_tweet(Tweet* tweet) {
        if (all_tweets.find(tweet->get_id()) == all_tweets.end())
            all_tweets.insert({tweet->get_id(), tweet});
    }

    void store_in_my_tweets(Tweet* tweet) {
        my_tweets.insert({tweet->get_id(), tweet});
    }

    std::vector<Tweet*> get_my_tweets() {
        return to_vector(my_tweets);
    }

    friend std::ostream& operator<<(std::ostream& os, Inbox inbox) {
        for (auto it = inbox.all_tweets.rbegin(); it != inbox.all_tweets.rend(); it++) {
            if (it->second->is_deleted())
                continue;
            os << *it->second << '\n';
        }
        return os;
    }
};