#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>
#include "motoca.hpp"
enum Commands {
    // init,
    // buy,
    // drive,
    // enter,
    // honk,
    // leave
};

struct Cases {
    Motorcycle* bike;

    // Receives the addres of a Motorcycle object
    Cases(Motorcycle* bike = nullptr) : 
        bike { bike } {
    }
    
    void identifier() {
        std::string line {""};
        std::string command{""};
        do {
            line = "";
            command = "";
            std::cout << "$";
            std::getline(std::cin >> std::ws, line);
            std::stringstream ss { line };
            ss >> command;
            if (command == "init") {
                int power;
                ss >> power;
                *bike = init(power);
            } else if (command == "buy") {
                int time;
                ss >> time;
                bike->buy(time);
            } else if (command == "drive") {
                int time;
                ss >> time;
                bike->drive(time);
            } else if (command == "enter") {
                std::string name;
                int age;
                ss >> name;
                ss >> age;
                Person* person = new Person { name, age };
                if (bike->enter(person)) {
                    std::cout << "fail: there is already someone on the bike\n";
                }
            } else if (command == "honk") {
                bike->honk();
            } else if (command == "leave") {
                bike->leave();
            } else if (command == "show") {
                bike->show();
            }
        } while(command != "end");
    }

    Motorcycle init(int power = 1) {
        Motorcycle bike { power };
        return bike;
    }

};