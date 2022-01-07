#include <iostream>
#include "car.hpp"
#include "tyres.hpp"
#include "driver.hpp"
#include "race-car.hpp"
#include "formula-1-car.hpp"

int main() {
    // Car car;
    // car.isItMax();
    // car.isItGlockGoingSlowly();
    std::shared_ptr<Driver> max = std::make_shared<Driver>("Max", 24, 99);
    std::cout << (*max) << '\n';

    Car car(4, 100);
    std::cout << "antes\n";
    car.addDriver(max);
    std::cout << "depois\n";
    std::cout << "car " << car.speed() << '\n';

    RaceCar race_car(450, 10, Tyre::medium);
    race_car.addDriver(max);

    FormulaOne formula_1_car(Tyre::soft, Scuderia::mclaren);
    formula_1_car.addDriver(max);

    std::cout << car << '\n';
    std::cout << race_car << '\n';
    std::cout << formula_1_car << '\n';
    car.race(formula_1_car);
    std::cout << car.speed() << " " << race_car.speed() << " " << formula_1_car.speed() << '\n'; 
    std::cout << formula_1_car.developPower() << '\n';
    std::cout << formula_1_car.developAeroDynamic() << '\n';
    std::cout << car.speed() << " " << race_car.speed() << " " << formula_1_car.speed() << '\n'; 
}