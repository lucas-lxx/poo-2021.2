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

    virtual void deposit(float value) {
        this->balance += value;
    }

    virtual void transfer(Account* other_account, float value = 0) {
        if (other_account != nullptr) {
            other_account->balance += value;
            this->balance -= value;
        } else {
            throw std::runtime_error("Account does not exists");
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