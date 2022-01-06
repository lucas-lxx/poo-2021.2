#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <memory>
#include "client.hpp"


class Sala {
private:
    std::vector<std::shared_ptr<Client>> sala{};
    
    // Returns the position on the vector if the person is present
    // If there is no one present that matches, then returns -1
    int isPresent(const std::string& name) {
        for (auto i = 0; i < (int) getCadeiras().size(); i++) {
            if (getCadeiras()[i] != nullptr) {
                if (getCadeiras()[i]->getId() == name) {
                    return i;
                }
            }
        }
        return std::string::npos;
    }

    // Returns true if the chair is available
    bool isChairAvailable(int chair) {
        if (chair < (int) getCadeiras().size()) {
            if (getCadeiras()[chair] == nullptr) {
                return true;
            } else {
                std::cout << "fail: this chair is not available\n";
                return false;
            }
        }
        std::cout << "fail: there is no chair with this number\n";
        return false;
    }

public:
    ///////////////////////////////////////////////////////////////////////////
    //////////////Constructor//////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Sala(int capacity = 0) :
        sala(capacity, nullptr) {
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Methods/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    // Cancels the chair of the peron at the cinema and changes it to available
    void cancel(const std::string& id) {
        int check = isPresent(id);
        if (check != std::string::npos) {
            getCadeiras()[check] = nullptr;
        } else {
            std::cout << "fail: this client is not at the cinema\n";
        }
    }

    // Returns true if it was possible to make a reservation
    bool reservation(std::string id, std::string fone, int chair) {
        if (isPresent(id) == std::string::npos) {
            if (isChairAvailable(chair)) {
                getCadeiras()[chair] = std::make_shared<Client>(id, fone);
                return true;
            }
            return false;
        }
        std::cout << "fail: this person is already at the cinema\n";
        return false;
    }

    // Returns the vector with the cinema's chairs
    std::vector<std::shared_ptr<Client>>& getCadeiras() {
        return this->sala;
    }


    ///////////////////////////////////////////////////////////////////////////
    ///////////////Print Methods///////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    void show() {
        int count{0};
        std::cout << "[ ";
        for (auto i : getCadeiras()) {
            if (i == nullptr) {
                std::cout << '(' << count << ")---- ";
            } else {
                std::cout << '(' << count << ") " << *i << ' ';
            }
            count++;
        }
        std::cout << "]\n";
    }
};


class Cases {
public:

    void case_identifier() {
        std::string line{""};
        std::string command{""};
        std::shared_ptr<Sala> sala = std::make_shared<Sala>();
        while(true) {
            line = "";
            command = "";
            std::cout << "$ ";
            std::getline(std::cin >> std::ws, line);
            std::stringstream ss {line};
            ss >> command;
            if (command == "end") {
                break;
            } else if (command == "init") {
                int size;
                ss >> size;
                sala = std::make_shared<Sala>(size);
            } else if (command == "show") {
                sala->show();
            } else if (command == "reservation") {
                std::string name{"INV"};
                std::string fone{"INV"};
                int chair{-1};
                ss >> name >> fone >> chair;
                if (name == "INV") {
                    std::cout << "Name input invalid!\n";
                    continue;
                } else if (fone == "INV") {
                    std::cout << "Fone input invalid!\n";
                    continue;
                } else if (chair == -1) {
                    std::cout << "Chair input invalid!\n";
                    continue;
                }
                sala->reservation(name, fone, chair);
            } else if (command == "cancel") {
                std::string name;
                ss >> name;
                sala->cancel(name);
            } else if (command == "help") {
                std::cout << "init <number of chairs>: initializes the chairs of the cinema\n";
                std::cout << "show: shows all available chairs\n";
                std::cout << "reservation <name of the person reserving> <phone number> <desired chair>: makes the reservation of the desired chair\n";
                std::cout << "cancel: <name of the person>: cancels the reservation of someone\n";
            } else {
                std::cout << "fail: invalid command";
                std::cout << "use the command, help to view available commands\n";
            }
        }
    }
};