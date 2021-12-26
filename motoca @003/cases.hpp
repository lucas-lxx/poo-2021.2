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
    std::cout << "$enter " << *person << "\n";
    if (bike.enter(person)) {
        std::cout << "fail: the motorcycle is already occupied\n";
    }
}

void end() {
    std::cout << "$end\n\n";
    std::cout << "////////////////////\n";
}

void title(const std::string& str) {
    std::cout << "Case: " << str << '\n';
}

void enter_and_honk_case_v1() {
    title("entering the motorcycle and honking v1");
    Motorcycle kx;
    show(kx);
    honk(kx);
    Person person { "Marcos", 4 };
    enter(kx, &person);
    show(kx);
    honk(kx);
    Person person2 { "Marisa", 2 };
    enter(kx, &person2);
    show(kx);
    end();
}

Motorcycle init(int power) {
    std::cout << "$init " << power << '\n';
    Motorcycle yz { power };
    return yz;
}

void enter_and_honk_case_v2() {
    Motorcycle yz = init(5);
    show(yz);
}