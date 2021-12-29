#include <iostream>
#include <memory>
#include <list>
#include "lead.hpp"
#include "pencil.hpp"

int main() {

    Lead lead{"3B", 30, 0.3};
    std::cout << lead.usagePerSheet() << '\n';
}