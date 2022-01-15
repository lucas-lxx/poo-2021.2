#pragma once
#include <iostream>
#include <map>
#include <set>

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

    friend std::ostream& operator<<(std::ostream& os, Tweet tweet) {
        os << tweet.id << ":" << tweet.username << " (" << tweet.msg << ")" << " [";
        int len = tweet.likes.size();
        // std::cout << len << '\n';
        int count = 1;
        for (auto& user_liked : tweet.likes) {
            if (count >= len) {
                os << user_liked;
                break;
            }
            os << user_liked << ", ";
            count++;
        }
        os  << "]";
        return os;
    }

};