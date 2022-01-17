#include <iostream>
#include <sstream>
#include <exception>
#include "tweet.hpp"
#include "inbox.hpp"
#include "user.hpp"
#include "controller.hpp"
#include "../../cpp-functional/auxiliar.hpp"

int main() {
    Controller controller;

    while (true) {
        std::string line;
        std::string command;
        // std::cout << "$ ";
        std::getline(std::cin >> std::ws, line);
        std::cout << "$" << line << '\n';
        std::stringstream ss{line};
        command = aux::read<std::string>(ss);
        try {
            if (command == "end") {
                break;
            } else if (command == "show") {
                std::cout << controller;
            } else if (command == "addUser") {
                std::string username = aux::read<std::string>(ss);
                controller.add_user(username);
            } else if (command == "follow") {
                auto [follower, followed] = aux::parse<std::string, std::string>(ss);
                controller.get_user(follower)->follow(controller.get_user(followed));
            } else if (command == "unfollow") {
                auto [follower, unfollowed] = aux::parse<std::string, std::string>(ss);
                controller.get_user(follower)->unfollow(unfollowed);
            } else if (command == "timeline") {
                std::string name = aux::read<std::string>(ss);
                std::cout << *controller.get_user(name)->get_inbox();
            } else if (command == "timeline-new") {
                std::string name = aux::read<std::string>(ss);
                std::cout << controller.get_user(name)->get_inbox()->get_unread();
            }  else if (command == "tweet") {
                std::string username = aux::read<std::string>(ss);
                std::string tweet;
                std::getline(ss >> std::ws, tweet);
                controller.send_tweet(username, tweet);
            } else if (command == "like") {
                auto [username, tweet_id] = aux::parse<std::string, int>(ss);
                controller.get_user(username)->like(tweet_id);
            } else {
                throw std::runtime_error("fail: command not found");
            }
        } catch (const std::runtime_error& e) {
            std::cout << e.what() << '\n';
        }
    }
}