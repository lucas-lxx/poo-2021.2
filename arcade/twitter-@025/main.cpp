#include <iostream>
#include <sstream>
#include <exception>
#include "tweet.hpp"
#include "inbox.hpp"
#include "user.hpp"
#include "controller.hpp"
#include "../../cpp-functional/auxiliar.hpp"
#include "tweet-exception.hpp"

int main() {
    Controller controller;

    while (true) {
        std::string line;
        // std::cout << "$ ";
        std::getline(std::cin >> std::ws, line);
        std::cout << "$" << line << '\n';
        std::vector<std::string> command {aux::split(line, ' ')};
        try {
            if (command[0] == "end") {
                break;
            } else if (command[0] == "show") {
                std::cout << controller;
            } else if (command[0] == "addUser") {
                ////////////////////username////
                controller.add_user(command[1]);
            } else if (command[0] == "follow") {
                ////////////////////follower//////////////////////////////followed///
                controller.get_user(command[1])->follow(controller.get_user(command[2]));
            } else if (command[0] == "unfollow") {
                ////////////////////follower//////////////followed////
                controller.get_user(command[1])->unfollow(command[2]);
            } else if (command[0] == "timeline") {
                //////////////////////////////////user name////////////////
                std::cout << *controller.get_user(command[1])->get_inbox();
            } else if (command[0] == "tweet") {
                //////////////////////username///////////////////////tweet////////////////
                controller.send_tweet(command[1], aux::join(aux::slice(command, 2), " "));
            } else if (command[0] == "like") {
                controller.get_user(command[1])->like(std::stoi(command[2]));
            } else if (command[0] == "retweet") {
                controller.send_retweet(command[1], std::stoi(command[2]), aux::join(aux::slice(command, 3), " "));
            } else if (command[0] == "remove") {
                controller.remove_user(command[1]);
            } else {
                throw TweetException("fail: command not found");
            }
        } catch (const TweetException& e) {
            std::cout << e.what() << '\n';
        }
    }
}