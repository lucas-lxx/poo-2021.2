#include <iostream>
#include <exception>
#include <sstream>
#include <tuple>
#include <algorithm>
#include "account.hpp"
#include "customer.hpp"
#include "bank-agency.hpp"

template <typename T>
T read(std::stringstream& ss) {
    T t;
    ss >> t;
    return t;
}

template <typename... Args>
auto parse(std::istream& is) {
    std::tuple<Args...> t;
    apply([&is](auto&&... args) {((is >> args), ...);}, t);
    return t;
}

int main() {
    BankAgency bank;
    while (true) {
        try {
            std::string line{}, cmd{};
            // std::cout << "$ ";
            std::getline(std::cin >> std::ws, line);
            std::stringstream ss{line};
            ss >> cmd;
            std::cout << "$ " << line << '\n';
            if (cmd == "end") {
                break;
            } else if (cmd == "show") {
                std::cout << bank;
            } else if (cmd == "deposit") {
                auto [id, amount] = parse<int, float>(ss);
                bank.deposit(id, amount);
            } else if (cmd == "withdraw") {
                auto [id, amount] = parse<int, float>(ss);
                bank.withdraw(id, amount);
            } else if (cmd == "transfer") {
                auto [idFrom, idTo, amount] = parse<int, int, float>(ss);
                bank.transfer(idFrom, idTo, amount);
            } else if (cmd == "update") {
                bank.monthlyUpdate();
            } else if (cmd == "add") {
                auto [name] = parse<std::string>(ss);
                bank.addCustomer(name);
            } else {
                throw std::runtime_error("fail: invalid command");
            }
        } catch (std::runtime_error& e) {
            std::cout << e.what() << '\n';
        }
    }
}