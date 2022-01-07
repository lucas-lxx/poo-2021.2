#include <iostream>
#include <sstream>
#include <tuple>
#include "car.hpp"
#include "tyres.hpp"
#include "driver.hpp"
#include "race-car.hpp"
#include "formula-1-car.hpp"

int main() {
    // std::shared_ptr<Driver> max = std::make_shared<Driver>("Max", 24, 99);
    // std::cout << (*max) << '\n';

    // Car car(4, 100);
    // car.addDriver(max);
    // std::cout << "car " << car.speed() << '\n';

    // RaceCar race_car(450, 10, Tyre::medium);
    // race_car.addDriver(max);

    // FormulaOne formula_1_car(Tyre::soft, Scuderia::mclaren);
    // formula_1_car.addDriver(max);

    // std::cout << car << '\n';
    // std::cout << race_car << '\n';
    // std::cout << formula_1_car << '\n';
    // car.race(formula_1_car);
    // std::cout << car.speed() << " " << race_car.speed() << " " << formula_1_car.speed() << '\n'; 
    // std::cout << formula_1_car.developPower() << '\n';
    // std::cout << formula_1_car.developAeroDynamic() << '\n';
    // std::cout << car.speed() << " " << race_car.speed() << " " << formula_1_car.speed() << '\n'; 
    auto max = std::make_shared<Driver>("Max", 24, 99);
    auto lewis = std::make_shared<Driver>("Sir Lewis", 37, 95);

    Car car33;
    Car car44;

    car33.addDriver(max);
    car44.addDriver(lewis);

    std::cout << car33 << '\n';
    std::cout << car44 << '\n';

    std::cout << *max << '\n';
    std::cout << "Max's speed with car 33: " << car33.speed() << '\n';
    std::cout << *lewis << '\n';
    std::cout << "Lewis' speed with car 44: " << car44.speed() << '\n';
    car33.race(car44);
}