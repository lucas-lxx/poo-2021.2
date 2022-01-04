#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "../contato-@014/contact.hpp"

class Agenda {
private:
    std::list<Contact> contacts{};

    // std::list<Contact>::iterator findPosByName(std::string name) {

    // }

public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Contructor//////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Agenda(){
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Methods/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    bool addContact(std::string name, std::vector<Fone> fones) {
        Contact person{name};
        for (auto i : fones) {
            if (!person.addFone(i)) {
                std::cout << "fail: " << name << '\n';
                return false;
            }
        }
        this->contacts.push_back(person);
        return true;
    }

    std::list<Contact> getContacts() {
        return this->contacts;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Print Methods///////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, Agenda agenda) {
        for (auto i : agenda.contacts) {
            os << i << '\n';
        }
        return os;
    }
};