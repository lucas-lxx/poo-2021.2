#pragma once
#include <iostream>
#include <sstream>
#include <memory>
#include <tuple>
#include "contact.hpp"

template<typename... Args>
auto parse(std::istream& is) {
    std::tuple<Args...> t;
    std::apply([&is](auto&&... args) {((is >> args), ...);}, t);
    return t;
}

class Solver {
public:
    void help() {
        std::cout << "init <name>\n";
        std::cout << "show\n";
        std::cout << "add <id, number>\n";
        std::cout << "remove <index>\n";
        std::cout << "end\n";
    }

    void cases() {
        std::string line{""};
        std::string command{""};
        std::shared_ptr<Contact> contact{std::make_shared<Contact>()};
        while (true) {
            // std::cout << "$ ";
            std::getline(std::cin >> std::ws, line);
            std::stringstream ss{line};
            std::cout << "$ " << line << '\n';
            ss >> command;
            if (command == "init") {
                auto [name] = parse<std::string>(ss);
                contact = std::make_shared<Contact>(name);
            } else if (command == "show") {
                std::cout << *contact << '\n';
            } else if (command == "end") {
                break;
            } else if (command == "add") {
                auto [id, number] = parse<std::string, std::string>(ss);
                Fone fone{id, number};
                contact->addFone(fone);
            } else if (command == "remove") {
                auto [index] = parse<int>(ss);
                contact->removeFone(index);
            }
        }
    }
};