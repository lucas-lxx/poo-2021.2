#pragma once
#include <iostream>
#include <vector>
#include "../contato-@014/contact.hpp"

class Agenda {
private:
    std::vector<Contact> contacts{};

    // Returns the position of the contact, else returns -1
    int findPosByName(std::string name) {
        int count {0};
        for (auto i : this->contacts) {
            if (name == i.getName()) {
                return count;
            }
            count++;
        }
        return -1;
    }

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
        }
        this->contacts.push_back(person);
        return true;
    }



    std::vector<Contact> getContacts() {
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