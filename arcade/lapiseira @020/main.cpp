#include <iostream>
#include <memory>
#include <list>
#include "lead.hpp"
#include "pencil.hpp"

int main() {
    Lead lead {"HB", 40, 0.3};
    std::cout << lead << '\n';
    
    Pencil pencil {0.3};
    std::cout << pencil << '\n';
}