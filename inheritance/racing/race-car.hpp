#pragma once
#include <iostream>
#include "car.hpp"
#include "tyres.hpp"

class RaceCar : public Car {
private:
    int aero_dynamic_pressure{0};
    Tyre tyre_compound{Tyre::null};
public:

    // Driver, Aero dynamic pressure and tyre compound are to be initialized
    RaceCar(int power, int aero_dynamic_pressure = 0, Tyre tyre = Tyre::null):
        Car{1, power}, aero_dynamic_pressure{aero_dynamic_pressure}, tyre_compound{tyre} {
        Car::setType("Race car");
    }

    // Returns the speed of the car
    virtual int speed() const {
        auto driver = Car::getDriver();
        if (driver == nullptr)
            return Car::getPower() / Car::getPassengers();
        return (Car::getPower() / Car::getPassengers()) * driver->getSkill() + aero_dynamic_pressure + getRubness(tyre_compound);
    }

    // Returns the aerodynamic pressure of the car
    virtual int getAeroDynamicPressure() const {
        return aero_dynamic_pressure;
    }

    // Set the Aero dynamic pressure of the car
    virtual void setAeroDynamicPressure(int aero_dynamic_pressure) {
        this->aero_dynamic_pressure = aero_dynamic_pressure;
    }

    friend std::ostream& operator<<(std::ostream& os, RaceCar race_car) {
        const Car& car = race_car;
        os << car;
        return os;
    }
};