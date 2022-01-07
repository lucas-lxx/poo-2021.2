#pragma once
#include <iostream>
#include <memory>
#include "driver.hpp"

class Car {
private:
    std::string type{"Car"};
    std::shared_ptr<Driver> driver{nullptr};
    int passengers{4};
    int power{150};
    int myDucks{0};
    
public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Car(int passengers = 4, int power = 150) :
        type{"Car"}, driver{nullptr}, passengers{passengers}, power{power} {
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    virtual bool addDriver(std::shared_ptr<Driver> driver) {
        if (this->driver == nullptr) {
            this->driver = driver;
            return true;
        }
        return false;
    }

    virtual int speed() const {
        if (driver == nullptr)
            return power / passengers;
        return (power / passengers) * driver->getSkill();
    }

    virtual void race(const Car& car) {
        if (this->speed() > car.speed()) {
            std::cout << "My duck! Quack quack!\n";
            myDucks++;
        } else {
            std::cout << "Oh snap I got smoked\n";
        }
    }

    virtual void isItMax() {
        if (driver->getName() == "max" || driver->getName() == "Max") {
            std::cout << "https://www.youtube.com/watch?v=43HCYSXZ9GI&t=104s <- click it!\n";
        }
    }

    virtual void isItGlockGoingSlowly() {
        if (driver->getName() == "hamilton" || driver->getName() == "Hamilton") {
            std::cout << "https://www.youtube.com/watch?v=RAICZZVoZI8&t=19s <- click it!\n";
        }
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

    virtual std::string getType() const {
        return type;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    virtual void setMyDuck(int ducks) {
        this->myDucks = ducks;
    }

    virtual void setType(std::string new_type) {
        this->type = new_type;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << car.type << " power: " << car.power << ", Driver: " << car.driver->getName();
        return os;
    }
};

