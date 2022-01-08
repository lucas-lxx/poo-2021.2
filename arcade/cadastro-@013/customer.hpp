#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <exception>
#include <vector>
#include "account.hpp"



class Customer {
private:
    std::map<int, Account*> accounts;
    std::string customerId{""};

public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructors////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Customer(std::string customerId = ""): 
        customerId{customerId} {
    }

    ~Customer() {
        for (auto& account : this->accounts) {
            delete account.second;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Methods/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    void addAccount(Account* account) {
        if (account != nullptr) {
            int idCheck = account->getId();
            if (this->accounts.find(idCheck) != accounts.end()) {
                this->accounts[account->getId()] = account;
            } else {
                throw std::runtime_error("fail: there is already an account with this id");
            }
        } else {
            throw std::runtime_error("fail: invalid account");
        }
    }

    void addAccount(std::vector<Account*> accounts) {
        for (auto& account : accounts) {
            addAccount(account);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Get/Set Methods/////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    std::string getCustomerId() {
        return this->customerId;
    }

    std::map<int, Account*> getAccounts() {
        return this->accounts;
    }

    void setCustomerId(std::string customerId) {
        this->customerId = customerId;
    }

    void setAccounts(std::map<int, Account*> accounts) {
        this->accounts = accounts;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////PrintMethods////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

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