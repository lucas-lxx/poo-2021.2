#pragma once
#include <iostream>
#include <list>
#include "fone.hpp"

class Contact {
private:
    std::list<Fone> fones;
    std::string name{""};

    // Returns true if the index is in the range of the fone list
    bool inRange(int index) {
        if (index > -1 && index < this->fones.size()) {
            return true;
        }
        return false;
    }

    // If found returns the iterator of the fone searched 
    // If not returns the fone.end()
    std::list<Fone>::iterator isPresent(int index) {
        if (!inRange(index)) {
            return this->fones.end();
        }
        int count{0};
        for (auto it = this->fones.begin(); it != this->fones.end(); it++) {
            if (index == count) {
                this->fones.erase(it);
                return it;
            }
        }
        return this->fones.end();
    }
public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructor/////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Contact(std::string name = "") :
        name{name} {
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Methods/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    // Returns true if it's a valid fone number and adds it to the end of the list
    bool addFone(Fone fone) {
        if (!fone.isValid()) {
            return false;
        }
        this->fones.push_back(fone);
        return true;
    }

    // Returns true if the fone was removed successfully
    bool rmFone(int index) {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Get and Set Methods/////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    std::list<Fone> getFones() {
        return this->fones;
    }

    std::string getName() {
        return this->name;
    }

    // Sets the number only if it's a valid number
    bool setFones(Fone fone) {
        if (!addFone(fone)) {
            return false;
        }
        return true;
    }

    void setName(std::string name) {
        this->name = name;
    }
};