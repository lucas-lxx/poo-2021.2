#pragma once
#include <iostream>
#include <memory>
#include <list>

class Lead {
private:
    std::string hardness { "" };
    int size { 0 };
    float thickness { 0 };

public:
    Lead(std::string hardness = "", int size = 0, float thickness = 0) :
        hardness{hardness}, size{size}, thickness{thickness} {
    }

    ///////////////////////////////////////////////////////////////////////////
    ////////////////////Get and Set Methods////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    // Returns the Hardness of the lead
    std::string getHardness() {
        return this->hardness;
    }

    // Returns the Size of the lead
    int getSize() {
        return this->size;
    }

    // Returns the Thickness of the lead
    float getThickness() {
        return this->thickness;
    }

    // Sets the size of a lead
    // Returns true if it was a valid size
    bool setSize(int size) {
        if (size > 10) {
            this->size = size;
            return true;
        }
        return false;
    }

    friend std::ostream& operator<< (std::ostream& os, Lead lead) {
        os << "[" << lead.thickness << ":" << lead.hardness << ":" << lead.size << "]";
        return os;
    }
};