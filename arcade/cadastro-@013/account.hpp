#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <exception>

// class Customer {
// private:
//     std::map<std::string, Account> accounts;
//     std::string customerId{""};

// public:
//     Customer(std::string customerId = ""): 
//         customerId{customerId} {
//     }

//     void addAccount(Account* account) {
//         // accounts[account->getAccountId()] = account;
//     }

// };

class Account {
private:
    int id{0};
    std::string customerId{""};
protected:
    std::string type{""};
    float balance{0.0f};

public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructors////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Account(int id = 0, std::string clientId = {""}):
        id(id), customerId(clientId) {
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Methods/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    virtual void deposit(float amount) {
        this->balance += amount;
    }

    virtual void transfer(Account* other_account, float amount = 0) {
        if (other_account != nullptr) {
            other_account->balance += amount;
            this->balance -= amount;
        } else {
            throw std::runtime_error("fail: account not found");
        }
    }

    virtual void withdraw(float amount = 0) {
        if (amount > 0) {
            if (amount <= this->balance) {
                this->balance -= amount;
            } else {
                throw std::runtime_error("fail: insuficient funds");
            }
        } else {
            throw std::runtime_error("fail: invalid amount");
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Virtual Methods/////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    virtual void monthlyUpdate() = 0;

    ///////////////////////////////////////////////////////////////////////////
    ///////////////PrintMethods////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    friend std::ostream& operator<<(std::ostream& os, const Account& account) {
        os << account.id << ":" << account.customerId << ":" << account.balance << ":" << account.type;
        return os;
    }
};

class SavingsAccount : public Account {
public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructor/////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    SavingsAccount(int id = 0, std::string idCustomer = ""):
        Account(id, idCustomer) {        
        this->type = "SA";
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Methods/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    virtual void monthlyUpdate() {
        this->balance *= 1.01;
    }
};

class CheckingAccount : public Account {
public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructor/////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    CheckingAccount(int id = 0, std::string idCustomer = ""):
        Account(id, idCustomer) {
        this->type = "CA";
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Methods/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    virtual void monthlyUpdate() {
        this->balance -= 20;
    }
};