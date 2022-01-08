#include <iostream>
#include "account.hpp"
#include "customer.hpp"
#include "bank-agency.hpp"

// Prints two accounts to the terminal
// void showAccounts(Account& savings_account, Account& checking_account) {
//     std::cout << "savings: " << savings_account << "\nchecking: " << checking_account << '\n';
// }

int main() {
    // SavingsAccount savings_account{0, "Lucas"};
    // CheckingAccount checking_account{1, "Lucas"};

    // showAccounts(savings_account, checking_account);
    // savings_account.monthlyUpdate();
    // checking_account.monthlyUpdate();
    // std::cout << "-----\n";
    // showAccounts(savings_account, checking_account);
    Customer lucas;
    std::cout << lucas << '\n';
}