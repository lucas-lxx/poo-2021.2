#include <iostream>
#include <memory>
#include <list>
#include "lead.hpp"
#include "pencil.hpp"

int main() {
    std::shared_ptr<Lead> lead { new Lead {0.3, "4B", 30}};

    Pencil pencil {0.3};
    std::cout << pencil.insert(lead) << '\n';
    std::cout << pencil << '\n';
}