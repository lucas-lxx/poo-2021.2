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
            auto ca = new CheckingAccount(this->nextAccountId, customer->getCustomerId());
            customer->addAccount(ca);
            this->accounts.insert({this->nextAccountId, ca});
            this->nextAccountId++;
            auto sa = new SavingsAccount(this->nextAccountId, customer->getCustomerId());
            customer->addAccount(sa);
            this->accounts.insert({this->nextAccountId, sa});
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

    void deposit(int idAccount, float amount) {
        if (accounts.find(idAccount) != accounts.end()) {
            auto receiver_account = accounts.find(idAccount);
            receiver_account->second->deposit(amount);
        } else {
            throw std::runtime_error("fail: account not found");
        }
    }

    void monthlyUpdate() {
        for (auto& it : accounts) {
            it.second->monthlyUpdate();
        }
    }

    void transfer(int accountFromId, int accountToId, float amount) {
        if (accounts.find(accountFromId) != accounts.end()) {
            if (accounts.find(accountToId) != accounts.end()) {
                auto accountFrom = accounts.find(accountFromId)->second;
                accountFrom->transfer(accounts.find(accountToId)->second, amount);
            } else {
                throw std::runtime_error("fail: destination account not found");
            }
        } else {
            throw std::runtime_error("fail: source account not found");
        }
    }

    void withdraw(int accountId, float amount) {
        if (accounts.find(accountId) != accounts.end()) {
            auto account = accounts.find(accountId)->second;
            account->withdraw(amount);
        } else {
            throw std::runtime_error("fail: account not found");
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////PrintMethods////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, const BankAgency& bank) {
        os << "Customers:\n";
        for (auto& it : bank.customers) {
            os << *it.second << '\n';
        }
        os << "Accounts:\n";
        for (auto& it : bank.accounts) {
            os << *it.second << '\n';
        }
        return os;
    }

};