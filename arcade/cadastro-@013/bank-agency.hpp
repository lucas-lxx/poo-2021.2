#pragma once
#include <iostream>
#include "account.hpp"
#include "customer.hpp"

class BankAgency {
private:
    std::map<int, Account*> accounts;
    std::map<std::string, Customer*> customers;
    int nextAccountId{ 0 };

    Account* getAccount(int accountId) {
        auto idCheck = accounts.find(accountId);
        if (idCheck != accounts.end()) {
            return idCheck->second;
        } else {
            throw std::runtime_error("fail: no account found with this id");
        }
    }

    void addDefaulAccounts(Customer* customer) {
        if (customer != nullptr) {
            customer->addAccount(new CheckingAccount(this->nextAccountId, customer->getCustomerId()));
            this->nextAccountId++;
            customer->addAccount(new SavingsAccount(this->nextAccountId, customer->getCustomerId()));
            this->nextAccountId++;
        } else {
            throw std::runtime_error("addDefaulAccounts invalid Customer");
        }
    }

public:

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructors////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    BankAgency() {
    }

    ~BankAgency() {
        for (auto it : this->customers) {
            delete it.second;
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    ///////////////Methods/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    void addCustomer(std::string name) {
        auto customer = new Customer(name);
        customers.insert({name, customer});
        addDefaulAccounts(customer);
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////PrintMethods////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

};