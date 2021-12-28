#pragma once
#include <iostream>
#include <memory>
#include <list>
#include "lead.hpp"

class Pencil {
private:
    Lead lead {"HB", 30, 0.3};
    Lead lead2 {"H2", 40, 0.3};

    std::list<Lead*> barrel {&lead, &lead2};
    float thickness { 0 };
    Lead* tip { nullptr };

public:
    Pencil(float thickness = 0.0) :
        thickness{thickness} {
    }

    friend std::ostream& operator<<(std::ostream& os, std::list<Lead*> lead) {
        for (Lead* i : lead) {
            os << *i;
        }
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, Pencil& pencil) {
        os << "thickness: " << pencil.thickness << ", ";
        if (pencil.tip == nullptr) {
            os << "tip: [], ";
        } else {
            os << "tip: " << pencil.tip << ", ";
        }
        os << "barrel: {"; 
        os << &pencil.barrel;
        // for (Lead* i : pencil.barrel){
        //     os << *i;
        // }
        os << "}";
        return os;
    }
};