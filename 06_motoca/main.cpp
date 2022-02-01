#include <iostream>
#include "cases.hpp"
#include "motoca.hpp"


int main() {
    Motorcycle bike;
    Cases cases { &bike };
    cases.identifier();
}