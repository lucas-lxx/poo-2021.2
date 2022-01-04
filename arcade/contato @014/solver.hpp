#pragma once
#include <iostream>
#include "contact.hpp"

class Solver {
public:
    void help() {
        std::cout << "init <name>\n";
        std::cout << "show\n";
        std::cout << "add <id, number>\n";
        std::cout << "remove <index>\n";
        std::cout << "end\n";
    }
     
};