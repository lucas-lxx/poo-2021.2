#pragma once
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "../../cpp-functional/auxiliar.hpp"

class Tweet {
private:
    int id;
    std::set<std::string> likes;
    std::string username;
    std::string msg;

public:

    Tweet(int id = -1, std::string username = "", std::string msg = ""): 
        id{id}, username{username}, msg{msg} {
    }

    void like(std::string username) {
        if (likes.find(username) == likes.end()) {
            likes.insert(username);
            return;
        }
        throw std::runtime_error("fail: user " + username + " already liked");
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

    std::string get_likes() {
        if (this->likes.empty())
            return "";
        auto likes_str = aux::join(this->likes, " ");
        return likes_str;
    }

    friend std::ostream& operator<<(std::ostream& os, Tweet tweet) {
        os << ((-1) * tweet.id) << ":" << tweet.username << " (" << tweet.msg << ")";
        if (tweet.likes.size() > 0) {
            os << "[";
            os << tweet.get_likes();
            os  << "]";
        }
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