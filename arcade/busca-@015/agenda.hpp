#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "../contato-@014/contact.hpp"

class Agenda {
private:
    std::list<Contact> contacts{};

    // Returns the position of the contact, else returns -1
    std::list<Contact>::iterator findPosByName(std::string name) {
        for (auto it = this->contacts.begin(); it != this->contacts.end(); it++) {
            if ((*it).getName() == name) {
                return it;
            }
        }
        return this->contacts.end();
    }

public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Contructor//////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Agenda(std::list<Contact> contacts) :
        contacts{contacts} {
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Methods/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    // Returns true if it added all the numbers to the contact,
    // else it does not attributes any
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
        auto it {findPosByName(name)};
        if (it == this->contacts.end())
            return nullptr;
        return &(*it);
    }

    // Returns true if the contact was removed successfully
    bool rmContact(std::string name) {
        auto it {findPosByName(name)};
        if (it == this->contacts.end())
            return false;
        this->contacts.erase(it);
        return true;
    }

    // Returns a list with the contacts that have the argument pattern present
    std::list<Contact> search(std::string pattern) {
        std::list<Contact> found;
        for (auto it = this->contacts.begin(); it != this->contacts.end(); it++) {
            std::cout << it->getName().compare(pattern) << '\n';
            if (it->getName().find(pattern) != std::string::npos) {
                found.push_back((*it));
            } 
        }
        return found;
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