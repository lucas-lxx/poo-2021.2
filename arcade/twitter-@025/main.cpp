#include <iostream>
#include "tweet.hpp"
#include "inbox.hpp"

int main() {
    auto tweet = std::make_shared<Tweet>(0, "Lucas", "Hello!");
    // std::cout << tweet << '\n';
    tweet->like("Leh");
    // std::cout << tweet << '\n';
    tweet->like("Dan");
    // std::cout << tweet << '\n';
    tweet->like("Gil");
    // std::cout << tweet << '\n';
    tweet->like("Ró");
    // std::cout << tweet << '\n';
    tweet->like("Norma");
    // std::cout << tweet << '\n';
    Inbox inbox;
    std::cout << inbox;
    inbox.new_tweet(tweet);
    std::cout << "inbox tweet:\n" << inbox;
    std::cout << "====\n";
    auto tweet2 = std::make_shared<Tweet>(1, "Lucas", "Functional programming!");
    inbox.new_tweet(tweet2);
    tweet2->like("David");
    std::cout << "inbox tweet2:\n" << inbox;
}