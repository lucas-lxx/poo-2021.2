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
            if (!driver->isDriving()) {
                this->driver = driver;
                this->driver->setDriving(true);
                return true;
            }
            return false;
        }
        return false;
    }

    virtual int speed() const {
        if (driver == nullptr)
            return power / passengers;
        return (power / passengers) * driver->getSkill();
    }

    virtual void race(const Car& car) {
        auto difference = this->speed() - car.speed();
        if (difference > 0) {
            std::cout << "My duck! Quack quack!\n";
            myDucks++;
        } else {
            std::cout << "Oh snap I got smoked by, " << -difference << "\n";
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

    virtual void setPower(int new_power) {
        this->power = new_power;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << car.type << " power: " << car.power << ", Driver: " << (car.driver != nullptr ? car.driver->getName() : "None");
        return os;
    }
};

