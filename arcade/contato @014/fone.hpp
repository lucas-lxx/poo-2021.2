#pragma once
#include <iostream>


class Fone {
private:
    std::string id{"-"};
    std::string number{"-"};

    static bool validate(std::string number) {
        for (auto& i : number) {
            if (!std::isdigit(i - 0)) {
                if (!(i == '(' || i == ')' || i == '.')) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructor/////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Fone(std::string id = "-", std::string number = "-") {
        if (validate(number)) {
            this->id = id;
            this->number = number;
        } else {
            std::cout << "Invalid number!\n";
            return;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Methods/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    bool isValid() {
        return validate(this->number);
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Get and Set Methods/////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    std::string getId() {
        return this->id;
    }

    std::string getNumber() {
        return this->number;
    }

    void setId(std::string id) {
        this->id = id;
    }

    void setNumber(std::string number) {
        this->number = number;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Print Methods///////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, const Fone& fone) {
        os << fone.id << ":" << fone.number;
        return os;
    }
};