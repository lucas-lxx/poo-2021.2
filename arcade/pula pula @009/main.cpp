#include <iostream>
#include <memory>
#include <algorithm>
#include "kid.hpp"
#include "trampoline.hpp"

void show(Trampoline& tramps) {
    std::cout << tramps;
}

int main() {
    auto kid = std::make_shared<Kid>("Mi", 5);
    auto kid2 = std::make_shared<Kid>("Marcos", 5);
    std::cout << *kid << '\n';
    
    Trampoline tramps;
    show(tramps);

    tramps.arrive(kid);
    show(tramps);
    
    tramps.arrive(kid2);
    show(tramps);

    tramps.enter();
    show(tramps);

    tramps.enter();
    show(tramps);

    tramps.leave();
    show(tramps);

    tramps.leave();
    show(tramps);
}