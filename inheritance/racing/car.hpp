#pragma once
#include <iostream>
#include <memory>
#include "person.hpp"

class Car {
private:
    int passengers{4};
    int power{100};
    std::shared_ptr<Person> driver{nullptr};
    
public:
    Car(int passengers = 4, int driver = 1, int power = 100) :
        passengers(passengers), power(power) {
    }

    virtual ~Car() {
        std::cout << "The car got to the junkyard\n";
    }

    virtual int speed() {
        return power / passengers;
    }

    virtual void race(Car car) {
        std::cout << "Oh snap I got smoked\n";
    }

    virtual void isItMax() {
        std::cout << "https://www.youtube.com/watch?v=43HCYSXZ9GI&t=104s <- click it!\n";
    }

    virtual void isItGlockGoingSlowly() {
        std::cout << "https://www.youtube.com/watch?v=RAICZZVoZI8&t=19s <- click it!\n";
    }
};

