#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <memory>
#include <map>
#include "client.hpp"


class Sala {
private:
    std::map<std::string, std::shared_ptr<Client>> customers;
    std::map<int, std::string> chairs;
    int cinema_size = {0};
    
    // Returns the iterator of the map if the person is present
    // If there is no one present that matches, then returns this->customers.end()
    auto isPresent(const std::string& name) {
        auto it = this->customers.find(name);
        if (it != this->customers.end()) {
            return it;
        }
        return this->customers.end();
    }

    // Returns true if the chair is available
    bool isChairAvailable(int chair) {
        if (chair < cinema_size) {
            if (this->chairs.find(chair) == this->chairs.end())
                return true;
        }
        return false;
    }

    bool isChairAvailableWarning(int chair) {
        if (chair < cinema_size) {
            if (this->chairs.find(chair) == this->chairs.end()) {
                return true;
            } else {
                std::cout << "fail: this chair is not available\n";
                return false;
            }
        }
        std::cout << "fail: there is no chair with this number\n";
        return false;
    }

    std::shared_ptr<Client> getClient(int chair) {
        auto key = this->chairs.find(chair);
        auto client = this->customers.find(key->second)->second;
        return client;
    }
public:
    ///////////////////////////////////////////////////////////////////////////
    //////////////Constructor//////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Sala(int capacity = 0) :
        cinema_size(capacity) {
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Methods/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    // Cancels the chair of the peron at the cinema and changes it to available
    void cancel(const std::string& id) {
        auto check = isPresent(id);
        if (check != this->customers.end()) {
            this->customers[id] = nullptr;
        } else {
            std::cout << "fail: this client is not at the cinema\n";
        }
    }

    // Returns true if it was possible to make a reservation
    bool reservation(std::string id, std::string fone, int chair) {
        if (isPresent(id) == this->customers.end()) {
            if (isChairAvailableWarning(chair)) {
                this->chairs.insert({chair, id});
                this->customers.insert({id, std::make_shared<Client>(id, fone)});
                return true;
            }
            return false;
        }
        std::cout << "fail: this person is already at the cinema\n";
        return false;
    }

    // Returns the vector with the cinema's chairs
    std::map<std::string, std::shared_ptr<Client>>& getCadeiras() {
        return this->customers;
    }


    ///////////////////////////////////////////////////////////////////////////
    ///////////////Print Methods///////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    void show() {
        std::cout << "[ ";
        for (int i = 0; i < cinema_size; i++) {
            if (isChairAvailable(i)) {
                std::cout << '(' << i << ")---- ";
            } else {
                auto client = getClient(i);
                if (client != nullptr) {
                    std::cout << '(' << i << ") " << (*client) << ' ';
                } else {
                    std::cout << '(' << i << ")---- ";
                }
            }
        }
        std::cout << "]\n";
    }
};


class Cases {
public:

    void case_identifier() {
        std::string line{""};
        std::string command{""};
        std::shared_ptr<Sala> customers = std::make_shared<Sala>();
        while(true) {
            line = "";
            command = "";
            // std::cout << "$ ";
            std::getline(std::cin >> std::ws, line);
            std::stringstream ss {line};
            std::cout << "$ " << line << '\n';
            ss >> command;
            if (command == "end") {
                break;
            } else if (command == "init") {
                int size;
                ss >> size;
                customers = std::make_shared<Sala>(size);
            } else if (command == "show") {
                customers->show();
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
                customers->reservation(name, fone, chair);
            } else if (command == "cancel") {
                std::string name;
                ss >> name;
                customers->cancel(name);
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