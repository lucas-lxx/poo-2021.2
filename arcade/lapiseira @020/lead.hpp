#pragma once
#include <iostream>
#include <memory>
#include <list>
#include <sstream>

class Lead {
private:
    std::string hardness { "" };
    int size { 0 };
    float thickness { 0 };

public:
    //////////////////////////////////////////////////////////////////////
    ///////////////Constructors///////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////

    // Enter the thicknes, hardness and it's size
    Lead(float thickness = 0, std::string hardness = "", int size = 0) :
        hardness{hardness}, size{size}, thickness{thickness} {
    }

    //////////////////////////////////////////////////////////////////////
    ///////////////Methods////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////

    // Returns the usage per sheet
    int usagePerSheet() {
        if (this->hardness == "HB") {
            return 1;
        } else if (this->hardness == "2B") {
            return 2;
        } else if (this->hardness == "4B") {
            return 4;
        } else if (this->hardness == "6B") {
            return 6;
        } else {
            std::cout << "Invalid hardness!\n";
            return 0;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Get and Set Methods/////////////////////////////////////////
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
        if (size >= 10) {
            this->size = size;
            return true;
        }
        this->size = 10;
        return false;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////To String///////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<< (std::ostream& os, Lead lead) {
        os << "[" << lead.thickness << ":" << lead.hardness << ":" << lead.size << "]";
        return os;
    }
};