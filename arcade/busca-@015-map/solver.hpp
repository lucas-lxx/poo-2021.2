#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <memory>
#include "agenda.hpp"

template <typename... Args>
auto parse(std::istream& is) {
    std::tuple<Args...> t;
    std::apply([&is](auto&&...args) {((is >> args), ...);}, t);
    return t;
}

class Solver {
public:
    void help() {
        std::cout << "$init,                                                                                 creates an agenda\n";
        std::cout << "$add <name> (<id0>:<number0>, <id2>:<number2>, ..., <idn>:<numbern>,                   adds to a contact fones\n";                
        std::cout << "$show,                                                                                 prints agenda on terminal\n";
        std::cout << "$rmFone <name> <index>,                                                                removes a specified fone\n";
        std::cout << "$rm <name>,                                                                            removes person\n";
        std::cout << "$search <pattern>,                                                                     searchs for pattern\n";
        std::cout << "$end,                                                                                  ends the code\n";
    }

    void cases() {
        std::shared_ptr<Agenda> agenda{std::make_shared<Agenda>()};
        std::string line{""};
        std::string command{""};
        while (true) {
            // std::cout << "$ ";
            std::getline(std::cin >> std::ws, line);
            std::stringstream ss{line};
            ss >> command;
            std::cout << "$ " << line << '\n';
            if (command == "init") {
                agenda = std::make_shared<Agenda>();
            } else if (command == "show") {
                std::cout << *agenda;
            } else if (command == "add") {
                auto [name] = parse<std::string>(ss);
                std::string string {ss.str()};
                std::vector<Fone> fones{pushFones(string, ss)};
                pushFones(string, ss);
                agenda->addContact(name, fones);
            } else if (command == "end") {
                break;
            } else if (command == "rmFone") {
                auto [name, index] = parse<std::string, int>(ss);
                agenda->rmFone(name, index);
            } else if (command == "rm") {
                auto [name] = parse<std::string>(ss);
                agenda->rmContact(name);
            } else if (command == "search") {
                auto [pattern] = parse<std::string>(ss);
                std::cout << agenda->to_string(agenda->search(pattern));
            } else if (command == "help") {
                help();
            } else {
                std::cout << "Invalid command, please try again\ntype 'help' to get a list of available commands\n";
            }
        }
    }

    // Returns true if found the specified character and changes to a ' '
    void breakPoint(std::string& string, const char& character) {
        for (auto& i : string) {
            if (character == i) {
                i = ' ';
            }
        }
    }

    std::vector<Fone> pushFones(std::string& string, std::stringstream& ss) {
        std::vector<Fone> fones;
        breakPoint(string, ':');
        ss << string;
        while (ss.rdbuf()->in_avail() != 0) {
            auto [id, number] = parse<std::string, std::string>(ss);
            Fone fone{id, number};
            fones.push_back(fone);
        }
        return fones;
    }
};