#include <iostream>
#include <memory>
#include <list>
#include "lead.hpp"
#include "pencil.hpp"

int main() {

    Lead lead{0.3, "4B", 30};
    std::cout << lead.usagePerSheet() << '\n';
}