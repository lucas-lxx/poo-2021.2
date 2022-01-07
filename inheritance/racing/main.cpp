#include <iostream>
#include "car.hpp"
#include "tyres.hpp"
#include "driver.hpp"
#include "race-car.hpp"

int main() {
    // Car car;
    // car.isItMax();
    // car.isItGlockGoingSlowly();
    std::shared_ptr<Driver> max = std::make_shared<Driver>("Max", 24, 99);
    std::cout << (*max) << '\n';

    Car car(max, 4, 100);
    std::cout << "car " << car.speed() << '\n';

    RaceCar racerCar(10, Tyre::medium, true, max);

    std::cout << "racecar " << racerCar.speed() << '\n';
}