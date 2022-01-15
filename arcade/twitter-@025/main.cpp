#include <iostream>
#include "tweet.hpp"

int main() {
    Tweet tweet(0, "Lucas", "Hello!");
    std::cout << tweet << '\n';
    tweet.like("Leh");
    std::cout << tweet << '\n';
    tweet.like("Dan");
    std::cout << tweet << '\n';
    tweet.like("Gil");
    std::cout << tweet << '\n';
    tweet.like("Ró");
    std::cout << tweet << '\n';
    tweet.like("Norma");
    std::cout << tweet << '\n';
}