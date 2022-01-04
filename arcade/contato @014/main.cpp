#include <iostream>
#include "contact.hpp"
#include "fone.hpp"

int main() {
    Fone fone{"oi", "(85)2201"};
    Fone fone2{"tim", "(85)22.33"};
    Fone fone3{"claro", "2244"};
    Contact c{"Lucas"};

    std::cout << "fone: " << c.addFone(fone) << '\n';
    std::cout << "fone2: " <<  c.addFone(fone2) << '\n';
    std::cout << "fone3: " <<  c.addFone(fone3) << '\n';
    std::cout << "show: " << c << '\n';
    std::cout << "remove: " << c.rmFone(2) << '\n';
    std::cout << "show: " << c << '\n';
}