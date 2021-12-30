#pragma once
#include <iostream>
#include <memory>
#include <list>
#include <algorithm>
#include "lead.hpp"

class Pencil {
private:
    std::list<std::shared_ptr<Lead>> barrel{};
    float thickness { 0 };
    std::shared_ptr<Lead> tip { nullptr };

public:
    //////////////////////////////////////////////////////////////////////
    ///////////////Constructors///////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////

    // Enter the desired thickness
    Pencil(float thickness = 0.0) :
        thickness{thickness} {
    }

    //////////////////////////////////////////////////////////////////////
    ///////////////Methods////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////

    // Returns true if the Lead has the same thickness as the Pencil and assigns it to the barrel
    // Else it will return false
    bool insert(std::shared_ptr<Lead> lead) {
        if (this->thickness == lead->getThickness()) {
            this->barrel.push_back(lead);
            return true;
        }
        return false;
    }

    // Returns true if there is no Lead on the tip
    // and the barrel is not empty
    bool pull() {
        if (this->tip == nullptr && this->barrel.front() != nullptr) {
            this->tip = this->barrel.front();
            this->barrel.pop_front();
            return true;
        }
        return false;
    }

    // Returns the addres of the lead that was on the tip and assigns nullptr to it
    // If there was no lead returns nullptr and a fail warning on the terminal
    std::shared_ptr<Lead> remove() {
        if (this->tip == nullptr) {
            std::cout << "fail: there is no lead on the tip\n";
            return nullptr;
        }
        return std::exchange(this->tip, nullptr);
    }

    // Writes and reassigns the lead size accordingly
    void writePage() {
        if (this->tip == nullptr) {
            std::cout << "fail: there's no lead on the tip\n";
        } else if (this->tip->getSize() <= 10) {
            std::cout << "fail: lead is too short\n";
        } else {
            if (!this->tip->setSize(this->tip->getSize() - this->tip->usagePerSheet())) {
                std::cout << "fail: incomplete page\n";
            }
        }
    }

    //////////////////////////////////////////////////////////////////////
    ///////////////To String//////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    friend std::ostream& operator<<(std::ostream& os, Pencil& pencil) {
        os << "thickness: " << pencil.thickness << ", ";
        if (pencil.tip == nullptr) {
            os << "tip: [], ";
        } else {
            os << "tip: " << *pencil.tip << ", ";
        }
        os << "barrel: {"; 
        for (auto i : pencil.barrel) {
            os << *i;
        }
        os << "}";
        return os;
    }

    void show() {
        std::cout << "thickness: " << this->thickness << ", ";
        if (this->tip == nullptr) {
            std::cout << "tip: [], ";
        } else {
            std::cout << "tip: " << *this->tip << ", ";
        }
        std::cout << "barrel: {"; 
        for (auto i : this->barrel) {
            std::cout << *i;
        }
        std::cout << "}\n";
    }

    //////////////////////////////////////////////////////////////////////
    ///////////////Cases//////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////  

    void case_identifier() {
        std::string line{""};
        std::string command{""};
        do {
            std::cout << "$ ";
            getline(std::cin >> std::ws, line);
            std::stringstream ss {line};
            ss >> command;
            if (command == "init") {
                float thickness;
                ss >> thickness;
                this->thickness = thickness;
            } else if (command == "show") {
                show();
            } else if (command == "insert") {
                float thickness;
                std::string hardness;
                int size;
                ss >> thickness >> hardness >> size;
                if (!insert(std::make_shared<Lead>(thickness, hardness, size))) {
                    std::cout << "fail: wrong lead thickness\n";
                }
            } else if (command == "pull") {
                if (!pull()) {
                    if (this->barrel.front() == nullptr) {
                        std::cout << "fail: there's no lead on the barrel\n";
                    } else {
                        std::cout << "fail: the tip already have a lead\n";
                    }
                }
            } else if (command == "remove") {
                remove();
            } else if (command == "write") {
                writePage();
            }
        } while (line != "end");
    }
};