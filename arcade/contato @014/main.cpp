#include <iostream>
#include "contact.hpp"
#include "fone.hpp"

int main() {
    Fone fone{"oi", "(85)22a01"};
    std::cout << fone << '\n';
    std::cout << fone.isValid() << '\n';
}