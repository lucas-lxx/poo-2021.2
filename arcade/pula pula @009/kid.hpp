#pragma once
#include <iostream>
#include <memory>
#include <algorithm>

class Kid {
private:
    std::string name{""};
    int age{ 0 };

public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructor/////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////


    Kid(std::string name = "", int age = 0) :
        name{name}, age{age} {
    }


    ///////////////////////////////////////////////////////////////////////////
    ///////////////Get/Set Methods/////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    // Returns the age variable of the object
    int getAge() const {
        return this->age;
    }

    // Returns the name variable of the object
    std::string getName() const {
        return this->name;
    }

    // Sets the age variable of the object
    void setAge(int age) {
        if (age > 0) {
            this->age = age;
        } else {
            std::cout << "fail: invalid age\n";
        }
    }

    // Sets the name variable of the object
    void setName(std::string name) {
        this->name = name;
    }


    ///////////////////////////////////////////////////////////////////////////
    ///////////////To String Methods///////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, const Kid& kid) {
        os << kid.name << ":" << kid.age;
        return os;
    }


};