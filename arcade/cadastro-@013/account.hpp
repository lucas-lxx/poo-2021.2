#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <exception>
#include <iomanip>

class Account {
private:
    int id{0};
    std::string customerId{""};
protected:
    std::string type{""};
    float balance{00.00f};

public:
    ///////////////////////////////////////////////////////////////////////////
    ///////////////Constructors////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Account(int id = 0, std::string clientId = {""}):
        id(id), customerId(clientId) {
    }

    virtual ~Account() {
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
    ///////////////Get Methods/////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    virtual float getBalance() {
        return this->balance;
    }

    virtual std::string getCustomerId() {
        return this->customerId;
    }

    virtual int getId() {
        return this->id;
    }

    virtual std::string getType() {
        return this->type;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////PrintMethods////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, Account& account) {
        os << account.id << ":" << account.customerId << ":" << std::fixed << std::setprecision(2) << account.balance << ":" << account.type;
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

    virtual ~SavingsAccount() {
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

    virtual ~CheckingAccount() {
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////Methods/////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    virtual void monthlyUpdate() {
        this->balance -= 20;
    }
};