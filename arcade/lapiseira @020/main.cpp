#include <iostream>
#include <memory>
#include <list>
#include "lead.hpp"
#include "pencil.hpp"

int main() {
    std::shared_ptr<Lead> lead { new Lead {0.3, "4B", 30}};
    std::shared_ptr<Lead> lead2 { new Lead {0.3, "HB", 80}};

    Pencil pencil {0.3};
    // std::cout << pencil.insert(lead) << '\n';
    // std::cout << pencil << '\n';
    // std::cout << pencil.insert(lead2) << '\n';
    // std::cout << pencil << '\n';
    
    std::cout << pencil << '\n';
    std::cout << pencil << '\n';
}