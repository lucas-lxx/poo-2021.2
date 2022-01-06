#pragma once
#include <iostream>
#include <list>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "../contato-@014/contact.hpp"

class Agenda {
private:
    std::unordered_map<std::string, Contact> contacts{};

    // Returns the position of the contact, else returns -1
    std::list<Contact>::iterator findPosByName(std::string name) {
        for (auto it = this->contacts.begin(); it != this->contacts.end(); it++) {
            if ((*it).getName() == name) {
                return it;
            }
        }
        return this->contacts.end();
    }

    // Returns a pointer to the contact or else returns nullptr
    Contact* findContact(std::string name) {
        auto it {findPosByName(name)};
        if (it == this->contacts.end())
            return nullptr;
        return &(*it);
    }

public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Contructor//////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Agenda() {
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
            this->contacts.sort([](Contact a, Contact b) {return a.getName() < b.getName();});
            return true;
        }
        if (!cont->addFone(fones))
            return false;
        return true;
    }

    void rmFone(const std::string& name, const int& index) {
        findContact(name)->removeFone(index);
    }

    // Returns true if the contact was removed successfully
    bool rmContact(std::string name) {
        auto it {findPosByName(name)};
        if (it != this->contacts.end()) {
            this->contacts.erase(it);
            return true;
        }
        return false;
    }

    // Returns a list with the contacts that have the argument pattern present
    std::list<Contact> search(std::string pattern) {
        std::list<Contact> found;
        for (auto& pair : this->contacts) {
            std::stringstream ss;
            ss << pair.second;
            if (ss.str().find(pattern) != std::string::npos) {
                found.push_back(pair.second);
            } 
        }
        return found;
    }

    std::unordered_map<std::string, Contact> getContacts() {
        return this->contacts;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Print Methods///////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    std::string to_string(std::list<Contact> contacts) {
        std::stringstream ss;
        for (auto& i : contacts) {
            ss << i << '\n';
        }
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& os, Agenda agenda) {
        os << "Agenda:\n";
        for (auto i : agenda.contacts) {
            os << i << '\n';
        }
        return os;
    }
};