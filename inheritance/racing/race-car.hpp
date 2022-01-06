#pragma once
#include <iostream>
#include "car.hpp"
#include "tyres.hpp"

class RaceCar : public Car {
private:
    int aeroDynamicPressure{0};
    Tyre tyreCompound{Tyre::null};
    bool turbo{true};
public:
    RaceCar(int aeroDynamicPressure = 0, Tyre tyre = Tyre::null, bool turbo=true, int passengers = 1, int power = 10):
        aeroDynamicPressure{aeroDynamicPressure}, tyreCompound{tyre}, turbo{turbo}, Car{passengers, power} {
    }


};