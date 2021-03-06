#pragma once
#include <iostream>
#include <map>
#include "inbox.hpp"
#include "tweet-exception.hpp"

class User {
private:
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;
    std::shared_ptr<Inbox> inbox;
    std::string username;

    // adds tweet to the followers inboxes
    void store_tweet_followers(Tweet* tweet) {
        for (auto it : followers) {
            it.second->get_inbox()->store_tweet(tweet);
        }
    }

    void store_tweet_this_account(Tweet* tweet) {
        this->inbox->store_tweet(tweet);
        if (tweet->get_sender() == username)
            this->inbox->store_in_my_tweets(tweet);
    }

public:

    User(std::string username = ""): 
        username{username} {
        this->inbox = std::make_shared<Inbox>();
    }

    // this object add other to this->following, and other object adds this to other.followers
    void follow(User* other) {
        // other_sign is a pair [iterator, bool]
        // sign is true when insert is succesfull
        auto [it_other, boolean] = other->followers.insert({username, this});
        if (boolean) {
            this->following.insert({other->username, other});
            return;
        }
        throw TweetException("fail: " + this->username + " already follows " + other->username);
    }

    // this object unfollows the object with the parameter username
    void unfollow(std::string username) {
        auto it_user = following.find(username);
        if (it_user != following.end()) {
            this->inbox->rm_tweets_from(it_user->second->username);
            it_user->second->followers.erase(it_user->second->followers.find(this->username));
            following.erase(it_user);
            return;
        }
        throw TweetException("fail: user not found");
    }

    Inbox* get_inbox() {
        return this->inbox.get();
    }

    void like(int tweet_id) {
        inbox->get_tweet(tweet_id)->like(this->username);
    }

    void store_tweet(Tweet* tweet) {
        store_tweet_followers(tweet);
        store_tweet_this_account(tweet);
    }

    void unfollow_all() {
        for (auto& i : following)
            i.second->followers.erase(this->username);
        following.clear();
    }

    void reject_all() {
        for (auto& i:followers) 
            i.second->following.erase(this->username);
        followers.clear();
    }

    friend std::ostream& operator<<(std::ostream& os, User user) {
        os << user.username << '\n';
        os << " following [";
        int count {1};
        for (auto i : user.following) {
            if (count >= (int) user.following.size()) {
                os << i.second->username;
                count = 1;
                break;
            }
            os << i.second->username << ", ";
            count++;
        }
        os << "]\n";

        os << " followers [";
        for (auto i : user.followers) {
            if (count >= (int) user.followers.size()) {
                os << i.second->username;
                break;
            }
            os << i.second->username << ", ";
            count++;
        }
        os << "]\n";
        return os;
    }
    
};