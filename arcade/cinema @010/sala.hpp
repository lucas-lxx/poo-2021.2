#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include "client.hpp"


class Sala {
private:
    std::vector<std::shared_ptr<Client>> sala{};
    
    // Returns true if the person already has a reservation
    bool isPresent(const std::string& name) const {
        for (std::shared_ptr<Client> i : sala) {
            if (i != nullptr) {
                if (i->getId() == name) {
                    return true;
                }
            }
        }
        return false;
    }

    // Returns true if the chair is available
    bool isChairAvailable(int chair) {
        if (chair < (int) this->sala.size()) {
            if (this->sala[chair] == nullptr) {
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

    // Returns true if it was possible to make a reservation
    bool reservation(std::string id, std::string fone, int chair) {
        if (!isPresent(id)) {
            if (isChairAvailable(chair)) {
                this->sala[chair] = std::make_shared<Client>(id, fone);
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////////
    //////////////Print Methods////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    void show() const {
        int count{0};
        std::cout << "[ ";
        for (auto i : this->sala) {
            if (i == nullptr) {
                std::cout << count << "---- ";
            } else {
                std::cout << *i << ' ';
            }
            count++;
        }
        std::cout << "]\n";
    }
};