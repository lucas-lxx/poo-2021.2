#pragma once
#include <iostream>
#include <memory>
#include "driver.hpp"

class Car {
private:
    std::shared_ptr<Driver> driver{nullptr};
    int passengers{4};
    int power{150};
    int myDucks{0};
    
public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Car(std::shared_ptr<Driver> driver = nullptr, int passengers = 4, int power = 150) :
        driver{driver}, passengers{passengers}, power{power} {
    }

    virtual ~Car() {
        std::cout << "The car got to the junkyard\n";
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    virtual int speed() const {
        if (driver == nullptr)
            return power / passengers;
        return (power / passengers) * driver->getSkill();
    }

    virtual void race(const Car& car) {
        if (this->speed() > car.speed()) {
            std::cout << "My duck! Quaqua\n";
            myDucks++;
        } else {
            std::cout << "Oh snap I got smoked\n";
        }
    }

    virtual void isItMax() {
        std::cout << "https://www.youtube.com/watch?v=43HCYSXZ9GI&t=104s <- click it!\n";
    }

    virtual void isItGlockGoingSlowly() {
        std::cout << "https://www.youtube.com/watch?v=RAICZZVoZI8&t=19s <- click it!\n";
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    virtual std::shared_ptr<Driver> getDriver() const {
        return driver;
    }

    virtual int getMyDucks() const {
        return myDucks;
    }

    virtual int getPower() const {
        return power;
    }

    virtual int getPassengers() const {
        return passengers;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    virtual void setMyDuck(int ducks) {
        this->myDucks = ducks;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << "Car: " << car.power << " duck counter: " << car.myDucks;
        return os;
    }
};

