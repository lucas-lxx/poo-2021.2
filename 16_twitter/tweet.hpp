#pragma once
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "../cpp-functional/auxiliar.hpp"
#include "tweet-exception.hpp"

class Tweet {
private:
    int id;
    std::set<std::string> likes;
    std::string username;
    std::string msg;
    Tweet* retweet;
    bool deleted;

public:

    Tweet(int id = -1, std::string username = "", std::string msg = ""): 
        id{id}, username{username}, msg{msg} {
        this->retweet = nullptr;
        this->deleted = false;
    }

    void like(std::string username) {
        if (likes.find(username) == likes.end()) {
            likes.insert(username);
            return;
        }
        throw TweetException("fail: user " + username + " already liked");
    }

    std::string get_sender() {
        return this->username;
    }

    int get_id() {
        return this->id;
    }

    std::string get_tweet() {
        return this->msg;
    }

    bool is_deleted() {
        return this->deleted;
    }

    void set_deleted() {
        this->deleted = true;
    }

    void set_retweet(Tweet* tweet) {
        this->retweet = tweet;
    }

    std::string get_likes() {
        if (this->likes.empty())
            return "";
        auto likes_str = aux::join(this->likes, " ");
        return likes_str;
    }

    friend std::ostream& operator<<(std::ostream& os, Tweet tweet) {
        if (tweet.is_deleted()) {
            os << "this tweet was deleted";
            return os;
        }
        os << tweet.id << ":" << tweet.username << " (" << tweet.msg << ")";
        if (tweet.likes.size() > 0)
            os << "[" << tweet.get_likes() << "]";
        if (tweet.retweet != nullptr)
            os << "\n  " << *tweet.retweet;
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, const std::vector<Tweet>& tweets) {
        for (auto& i : tweets) {
            os << i << '\n';
        }
        os << '\n';
        return os;
    }

};