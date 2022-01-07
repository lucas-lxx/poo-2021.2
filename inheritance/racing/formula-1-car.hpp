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
}

class FormulaOne : public RaceCar {
private:
    Scuderia scuderia{Scuderia::null};

public:

    FormulaOne(Tyre tyre = Tyre::null, Scuderia scuderia = Scuderia::null) :
        RaceCar{scuderiaPower(scuderia), scuderiaAeroDynamic(scuderia), tyre} {
        Car::setType("F1 car");
    }

    virtual bool developmentSuccess() {
        srand(time(0));
        if (rand() % 2 == 0) {
            return true;
        }
        return false;
    }

    virtual bool developPower() {
        if (developmentSuccess()) {
            Car::setPower(Car::getPower() + 1);
            return true;
        }
        return false;
    }

    virtual bool developAeroDynamic() {
        if (developmentSuccess()) {
            RaceCar::setPower(Car::getPower() + 1);
            return true;
        }
        return false;
    }
};