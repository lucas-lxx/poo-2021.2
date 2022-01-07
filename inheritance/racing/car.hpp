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
                std::cout << driver->getName() << " got to " << this->type << " successfully" << std::endl;
                return true;
            }
            std::cout << driver->getName() << " is already driving!" << std::endl;
            return false;
        }
        std::cout << "Car already has a driver!" << std::endl;
        return false;
    }

    virtual bool removeDriver() {
        if (this->driver != nullptr) {
            this->driver->setDriving(false);
            this->driver = nullptr;
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
        if (this->driver == nullptr || car.driver == nullptr) {
            std::cout << "Unable to race without both drivers\n";
            return;
        }
        std::cout << this->driver->getName() << " challenged " << car.getDriver()->getName() << " for a race\n";
        std::cout << this->driver->getName() << " driving a " << this->type << " and " << car.driver->getName() << " driving a " << car.getType() << '\n';
        auto difference = this->speed() - car.speed();
        if (difference > 0) {
            std::cout << (*this->driver).getName() << " won!\n";
        } else {
            std:: cout << (*car.getDriver()).getName() << " won!\n";
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    virtual std::shared_ptr<Driver> getDriver() const {
        return driver;
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

