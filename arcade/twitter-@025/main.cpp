#include <iostream>
#include "tweet.hpp"
#include "inbox.hpp"
#include "user.hpp"

int main() {
    // auto tweet = std::make_shared<Tweet>(0, "Lucas", "Hello!");
    // // std::cout << tweet << '\n';
    // tweet->like("Leh");
    // // std::cout << tweet << '\n';
    // tweet->like("Dan");
    // // std::cout << tweet << '\n';
    // tweet->like("Gil");
    // // std::cout << tweet << '\n';
    // tweet->like("Ró");
    // // std::cout << tweet << '\n';
    // tweet->like("Norma");
    // // std::cout << tweet << '\n';
    // Inbox inbox;
    // std::cout << inbox;
    // inbox.new_tweet(tweet);
    // std::cout << "inbox tweet:\n" << inbox;
    // std::cout << "====\n";
    // auto tweet2 = std::make_shared<Tweet>(1, "Lucas", "Functional programming!");
    // inbox.new_tweet(tweet2);
    // tweet2->like("David");
    // std::cout << "inbox tweet2:\n" << inbox;

    auto user = std::make_shared<User>("Lucas");
    auto user2 = std::make_shared<User>("Leh");
    auto user3 = std::make_shared<User>("La");
    auto user4 = std::make_shared<User>("Ró");
    user->follow(user2);
    user->follow(user3);
    user->follow(user4);
    // std::cout << *user;
    user->unfollow("Leh");
    // std::cout << *user;
    std::cout << (*user->get_inbox()) << '\n';
}