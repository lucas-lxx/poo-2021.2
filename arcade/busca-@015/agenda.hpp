#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "../contato-@014/contact.hpp"

class Agenda {
private:
    std::list<Contact> contacts{};

    // std::list<Contact>::iterator findPosByName(std::string name) {
    //     for (auto i : this->contacts) {
    //     }
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

    // Returns true if it added all the number to the contact
    // Else it does not attributes any
    bool addContact(std::string name, std::vector<Fone> fones) {
        Contact person{name};
        if (!person.addFone(fones)) {
            std::cout << "failed to add " << name << "'s contact\n";
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