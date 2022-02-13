#pragma once
#include <iostream>
#include <random>
#include <chrono>
#include "race-car.hpp"

enum class Scuderia {
    null,
    ferrari,
    mercedes,
    red_bull,
    mclaren,
    williams
};

int scuderiaPower(Scuderia scuderia = Scuderia::null) {
    switch (scuderia){
        case (Scuderia::null):
            return 0;
        case (Scuderia::ferrari):
            return 825;
        case (Scuderia::mercedes):
            return 850;
        case (Scuderia::red_bull):
            return 840;
        case (Scuderia::mclaren):
            return 820;
        case (Scuderia::williams):
            return 800;
    }
    return -1;
}

int scuderiaAeroDynamic(Scuderia scuderia = Scuderia::null) {
    switch (scuderia){
        case (Scuderia::null):
            return 0;
        case (Scuderia::ferrari):
            return 80;
        case (Scuderia::mercedes):
            return 90;
        case (Scuderia::red_bull):
            return 100;
        case (Scuderia::mclaren):
            return 85;
        case (Scuderia::williams):
            return 80;
    }
    return -1;
}

std::string scuderiaName(Scuderia scuderia = Scuderia::mclaren) {
    if (scuderia == Scuderia::null)
        return "Null";
    if (scuderia == Scuderia::ferrari)
        return "Ferrari";
    if (scuderia == Scuderia::mercedes)
        return "Mercedes";
    if (scuderia == Scuderia::red_bull)
        return "Red Bull";
    if (scuderia == Scuderia::mclaren)
        return "McLaren";
    if (scuderia == Scuderia::williams) 
        return "Williams";
    return "";
}

class FormulaOne : public RaceCar {
private:
    Scuderia scuderia{};

    // Returns the success probability of the car
    virtual bool developmentSuccess() {
        srand(time(0));
        if (rand() % 2 == 0) {
            return true;
        }
        return false;
    }
public:

    FormulaOne(Tyre tyre = Tyre::FLAT_TYRE, Scuderia scuderia = Scuderia::null) :
        RaceCar{scuderiaPower(scuderia), scuderiaAeroDynamic(scuderia), tyre}, scuderia{scuderia} {
        Car::setType("F1 car");
    }

    virtual bool developPower() {
        if (developmentSuccess()) {
            Car::setPower(Car::getPower() + 5);
            return true;
        }
        return false;
    }

    virtual bool developAeroDynamic() {
        if (developmentSuccess()) {
            RaceCar::setPower(Car::getPower() + 5);
            return true;
        }
        return false;
    }

    virtual std::string getScuderia() {
        return scuderiaName(this->scuderia);
    }

    friend std::ostream& operator<<(std::ostream& os, FormulaOne& f1) {
        const Car& car = f1;
        os << car << ", Scuderia: " << f1.getScuderia();
        return os;
    }
};