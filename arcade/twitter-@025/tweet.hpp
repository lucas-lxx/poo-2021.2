#pragma once
#include <iostream>
#include <map>
#include <set>
#include <vector>

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

    friend std::ostream& operator<<(std::ostream& os, Tweet tweet) {
        os << tweet.id << ":" << tweet.username << " (" << tweet.msg << ")";
        int len = tweet.likes.size();
        if (tweet.likes.size() > 0) {
            int count = 1;
            os << "[";
            for (auto& user_liked : tweet.likes) {
                if (count >= len) {
                    os << user_liked;
                    break;
                }
                os << user_liked << ", ";
                count++;
            }
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