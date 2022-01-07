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
    RaceCar(int aeroDynamicPressure = 0, Tyre tyre = Tyre::null, bool turbo=true, std::shared_ptr<Driver> driver = nullptr, int passengers = 1, int power = 600):
        Car{driver, passengers, power}, aeroDynamicPressure{aeroDynamicPressure}, tyreCompound{tyre}, turbo{turbo} {
    }

    virtual int speed() const {
        auto driver = Car::getDriver();
        if (driver == nullptr)
            return Car::getPower() / Car::getPassengers();
        return (Car::getPower() / Car::getPassengers()) * driver->getSkill() + aeroDynamicPressure + getRubness(tyreCompound);
    }

};