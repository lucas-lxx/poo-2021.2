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
        for (auto& account : accounts) {
            delete account.second;
        }
    }

    void addAccount(Account* account) {
        this->accounts[account.getId()] = account;
    }

};