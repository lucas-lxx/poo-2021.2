#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <exception>
#include "account.hpp"



class Customer {
private:
    std::map<int, Account*> accounts;
    std::string customerId{""};

public:
    Customer(std::string customerId = ""): 
        customerId{customerId} {
    }

    ~Customer() {
        for (auto& account : this->accounts) {
            delete account.second;
        }
    }

    void addAccount(Account* account) {
        this->accounts[account->getId()] = account;
    }

    friend std::ostream& operator<<(std::ostream& os, const Customer& customer) {
        os << "- " << customer.customerId << '[';
        int count { 0 };
        for (auto& account : customer.accounts) {
            if (((int)customer.accounts.size() -1) == count) {
                os << account.second->getId();
                break;
            }
            os << account.second->getId() << ", ";
            count++;
        }
        os << ']';
        return os;
    }
};