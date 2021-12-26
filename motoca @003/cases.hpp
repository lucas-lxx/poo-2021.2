#pragma once
#include <iostream>
#include <algorithm>
#include "motoca.hpp"

void show(Motorcycle bike) {
    std::cout << "$show\n";
    bike.show();
}

void honk(Motorcycle bike) {
    std::cout << "$honk\n";
    bike.honk();
}

void enter(Motorcycle& bike, Person* person) {
    std::cout << "$enter\n";
    bike.enter(person);
}

void enter_and_honk_case() {
    Motorcycle kx;
    show(kx);
    honk(kx);
    Person person { "Marcos", 4 };
    enter(kx, &person);
    show(kx);
    honk(kx);
    
}

