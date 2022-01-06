#include <iostream>
#include "person.hpp"

class Driver : public Person {
private:
    int driverSkill{0};

public:
    Driver(std::string name = "", int age = 0, int skill = 0):
        Person{age, name}, driverSkill(skill) {
    }

    friend std::ostream& operator<<(std::ostream& os, const Driver& driver) {
        const Person& person = driver;
        os << "Driver: " << person.getName() << "skill: " << driver.driverSkill;
        return os;
    }
};