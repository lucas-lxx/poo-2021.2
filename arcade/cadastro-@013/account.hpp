#pragma once
#include <iostream>
#include <map>
#include <unordered_map>

class Customer {
private:
    std::map<std::string, Account> accounts;
    std::string customerId{""};

public:
    Customer(std::string customerId = ""): 
        customerId{customerId} {
    }

    void addAccount(Account* account) {
        // accounts[account->getAccountId()] = account;
    }

};

class Account {
private:
    std::string accountId{""};

public:
    Account(std::string account = ""):
        accountId(account) {
    }
};

class SavingsAccount : public Account {

};

class CheckingAccount : public Account {

};