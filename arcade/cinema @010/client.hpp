#pragma once
#include <iostream>

class Client {
private:
    std::string id;
    std::string fone;

public:
    Client(std::string id = "", std::string fone = "") :
        id{id}, fone{fone} {
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Get and Set Methods/////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    std::string getId() {
        return id;
    }

    std::string getFone() {
        return fone;
    }

    void setId(std::string id) {
        this->id = id;
    }

    void setFone(std::string fone) {
        this->fone = fone;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Print Methods///////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, Client client) {
        os << client.id << ":" << client.fone;
        return os;
    }

    void show() {
        std::cout << id << ":" << fone << '\n';
    }
};