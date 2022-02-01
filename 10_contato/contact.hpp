#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "fone.hpp"

class Contact {
private:
    std::list<Fone> fones;
    std::string name{""};

    // Returns true if the index is in the range of the fone list
    bool inRange(int index) {
        if (index > -1 && index < (int) this->fones.size()) {
            return true;
        }
        return false;
    }

    // If found returns the iterator of the fone searched 
    // If not returns the fone.end()
    std::list<Fone>::iterator isPresent(int index) {
        if (!inRange(index)) {
            std::cout << "fail: not in range\n";
            return this->fones.end();
        }
        int count{0};
        for (auto it = this->fones.begin(); it != this->fones.end(); it++) {
            if (index == count) {
                return it;
            }
            count++;
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

    // Returns true if it's a valid vector of fone numbers and adds them
    // to the end of the list
    bool addFone(std::vector<Fone> fones) {
        for (auto i : fones) {
            if (!addFone(i)) {
                return false;
            }
        }
        return true;
    }

    // Returns true if the fone was removed successfully
    bool removeFone(int index) {
        auto it = isPresent(index);
        if (it != fones.end()) {
            this->fones.erase(it);
            return true;
        }
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

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Print Method////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, Contact contact) {
        os << "- " << contact.name << " ";
        int count {0};
        for (auto i : contact.fones) {
            os << "[" << count << ":" << i << "] ";
            count++;
        }
        return os;
    }
};