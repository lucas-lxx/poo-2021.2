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
    Pencil(float thickness = 0.0) :
        thickness{thickness} {
    }


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