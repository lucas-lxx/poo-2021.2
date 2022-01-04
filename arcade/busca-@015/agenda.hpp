#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "../contato-@014/contact.hpp"

class Agenda {
private:
    std::list<Contact> contacts{};

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

    // Returns true if it added all the numbers to the contact
    // Else it does not attributes any
    bool addContact(std::string name, std::vector<Fone> fones) {
        Contact* cont = findContact(name);
        if (cont == nullptr) {
            Contact person{name};
            if (!person.addFone(fones)) 
                return false;
            this->contacts.push_back(person);
            this->contacts.sort([](Contact a, Contact b) {return a.getName() > b.getName();});
        } else {
            cont->addFone(fones);
        }
        return true;
    }

    // Returns a pointer to the contact or else returns nullptr
    Contact* findContact(std::string name) {
        auto pos {findPosByName(name)};
        if (pos == -1) {
            return nullptr;
        }
        std::list<Contact>::iterator it{this->contacts.begin()};
        return &(*std::next(it, pos));
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