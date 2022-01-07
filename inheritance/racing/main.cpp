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

    Car car(4, 100);
    car.addDriver(max);
    std::cout << "car " << car.speed() << '\n';

    RaceCar race_car(450, 10, Tyre::medium);
    race_car.addDriver(max);
    std::cout << car << '\n';
    std::cout << race_car << '\n';
}