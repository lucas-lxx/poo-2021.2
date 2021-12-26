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
            if (!(ss >> command)) {
                
            }
            if (command == "init") {
                *bike = init();
            } else if (command == "buy") {
                
            } else if (command == "drive") {

            } else if (command == "enter") {

            } else if (command == "honk") {
                bike->honk();
            } else if (command == "leave") {

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