#include <iostream>
#include <memory>
#include <list>
#include "lead.hpp"
#include "pencil.hpp"

int main() {
    std::shared_ptr<Lead> lead { new Lead {0.3, "4B", 11}};
    std::shared_ptr<Lead> lead2 { new Lead {0.3, "2B", 80}};

    Pencil pencil {0.3};

    pencil.insert(lead);
    pencil.pull();
    std::cout << pencil << '\n';
    // std::cout << "insert():   " << pencil.insert(lead) << '\n';
    // std::cout << "show():     " << pencil << '\n';

    // std::cout << "insert():   " << pencil.insert(lead2) << '\n';
    // std::cout << "show():     " << pencil << '\n';
    // std::cout << "pull():     " << pencil.pull() << '\n';
    // std::cout << "show():     " << pencil << '\n';
    // std::cout << "remove():   " << *pencil.remove() << '\n';
    // std::cout << "show():     " << pencil << '\n';
    
    // std::cout << "remove():   " << *pencil.remove() << '\n';
    // std::cout << "show():     " << pencil << '\n';
    pencil.writePage();
    std::cout << pencil << '\n';
}