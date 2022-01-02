#include <iostream>
#include <vector>
#include <memory>
#include "sala.hpp"
#include "client.hpp"

int main() {
    Sala sala{5};
    sala.show();

    std::cout << sala.reservation("Lucas", "2424", 3) << '\n';
    sala.show();
}