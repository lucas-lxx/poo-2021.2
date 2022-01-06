#pragma once
#include <iostream>

class Car {
private:
    int wheels{4};
    int passengers{4};
    int driver{1};
    int power{1};
    
public:
    Car(int wheels = 4, int passengers = 4, int driver = 1) :
        wheels(wheels), passengers(passengers), driver(driver) {
    }

    virtual ~Car() {
        std::cout << "The car got to the junkyard\n";
    }

    virtual void race() {
        std::cout << "Oh snap I got smoked\n";
    }

    virtual void isItMax() {
        std::cout << "https://www.youtube.com/watch?v=43HCYSXZ9GI&t=104s <- click it!\n";
    }

    virtual void isItGlockGoingSlowly() {
        std::cout << "https://www.youtube.com/watch?v=RAICZZVoZI8&t=19s <- click it!\n";
    }
};

