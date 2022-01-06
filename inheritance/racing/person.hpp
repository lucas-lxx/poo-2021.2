#pragma once
#include <iostream>

class Person {
private:
    int age{0};
    std::string name{""};

public:

    Person(int age = 0, std::string name = ""):
        age{age}, name{name} {
    }

    std::string getName() const {
        return name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << person.name << ":" << person.age;
        return os;
    }

};