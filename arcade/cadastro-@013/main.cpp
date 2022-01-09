#include <iostream>
#include "account.hpp"
#include "customer.hpp"
#include "bank-agency.hpp"

// Prints two accounts to the terminal
// void showAccounts(Account& savings_account, Account& checking_account) {
//     std::cout << "savings: " << savings_account << "\nchecking: " << checking_account << '\n';
// }

int main() {
    // // SavingsAccount savings_account{0, "Lucas"};
    // // CheckingAccount checking_account{1, "Lucas"};

    // // showAccounts(savings_account, checking_account);
    // // savings_account.monthlyUpdate();
    // // checking_account.monthlyUpdate();
    // // std::cout << "-----\n";
    // // showAccounts(savings_account, checking_account);
    // Customer lucas;
    // std::cout << lucas << '\n';

    BankAgency bank;
    bank.addCustomer("Lucas");
    std::cout << bank;
    std::cout << "=====\n";
    bank.deposit(0, 100);
    bank.deposit(1, 100);
    std::cout << bank;
    std::cout << "=====\n";
    bank.monthlyUpdate();
    std::cout << bank;
    std::cout << "=====\n";
    bank.addCustomer("Leh");
    bank.addCustomer("Joao");
    std::cout << bank;
    std::cout << "=====\n";
    bank.deposit(2, 50.3);
    bank.deposit(3, 23.44);
    bank.deposit(4, 409.33);
    bank.deposit(5, 2333.9);
    std::cout << bank;
    std::cout << "=====\n";
    bank.monthlyUpdate();
    std::cout << bank;
    std::cout << "=====\n";
    
}