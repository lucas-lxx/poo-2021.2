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

    // Returns true if the Lead has the same thickness as the Pencil
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
        if (this->barrel.front() == nullptr) {
            return false;
        }
        if (this->tip == nullptr) {
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
};