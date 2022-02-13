#pragma once
#include <iostream>

enum class Tyre {
    FLAT_TYRE,
    SOFT,
    MEDIUM,
    HARD
};

std::ostream& operator<<(std::ostream& os, const Tyre& tyre) {
    switch (tyre) {
        case (Tyre::FLAT_TYRE):
            return os << "Bono my tyres are gone";
        case (Tyre::SOFT):
            return os << "Soft tyres";
        case (Tyre::MEDIUM):
            return os << "Medium tyres";
        case (Tyre::HARD):
            return os << "Hard tyres";
    }
    return os;
}

int getRubness(const Tyre& tyre) {
    int rubness{0};
    switch (tyre) {
        case (Tyre::FLAT_TYRE):
            rubness = -100;
            break;
        case (Tyre::SOFT):
            rubness = 100;
            break;
        case (Tyre::MEDIUM):
            rubness = 75;
            break;
        case (Tyre::HARD):
            rubness = 50;
            break;
        default:
            rubness = 0;
            break;
    }
    return rubness;
}