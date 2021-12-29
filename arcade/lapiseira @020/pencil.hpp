#pragma once
#include <iostream>
#include <memory>
#include <list>
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

    //////////////////////////////////////////////////////////////////////
    ///////////////To String//////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    friend std::ostream& operator<<(std::ostream& os, Pencil& pencil) {
        os << "thickness: " << pencil.thickness << ", ";
        if (pencil.tip == nullptr) {
            os << "tip: [], ";
        } else {
            os << "tip: " << pencil.tip << ", ";
        }
        os << "barrel: {"; 
        for (auto i : pencil.barrel) {
            os << *i;
        }
        os << "}";
        return os;
    }
};