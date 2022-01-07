#pragma once
#include <iostream>

enum class Tyre {
    null,
    soft,
    medium,
    hard
};

std::ostream& operator<<(std::ostream& os, const Tyre& tyre) {
    switch (tyre) {
        case (Tyre::null):
            return os << "Bono my tyres are gone";
        case (Tyre::soft):
            return os << "Soft tyres";
        case (Tyre::medium):
            return os << "Medium tyres";
        case (Tyre::hard):
            return os << "Hard tyres";
    }
    return os;
}

int getRubness(const Tyre& tyre) {
    int rubness{0};
    switch (tyre) {
        case (Tyre::null):
            rubness = -100;
        case (Tyre::soft):
            rubness = 100;
        case (Tyre::medium):
            rubness = 75;
        case (Tyre::hard):
            rubness = 50;
    }
    return rubness;
}