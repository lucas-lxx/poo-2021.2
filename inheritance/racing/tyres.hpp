#pragma once
#include <iostream>

enum class Tyre {
    null,
    soft,
    medium,
    hard,
    softRain,
    heavyRain
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
        case (Tyre::softRain):
            return os << "Soft rain tyres";
        case (Tyre::heavyRain):
            return os << "Heavy rain tyres";
    }
    return os;
}