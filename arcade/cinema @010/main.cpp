#include <iostream>
#include <vector>
#include <memory>
#include "sala.hpp"
#include "client.hpp"

int main() {
    auto sclient = std::make_shared<Client>("Lucas", "3322");
    Client client {"Lucas", "3324"};

    std::cout << *sclient << '\n';
    std::cout << client << '\n';
    sclient->show();
    client.show();
}