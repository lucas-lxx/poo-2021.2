#include <iostream>
#include <exception>
#include <sstream>
#include "account.hpp"
#include "customer.hpp"
#include "bank-agency.hpp"

template <typename T>
T read(stringstream& ss) {
    T t;
    ss >> t;
    return t;
}

template <typename... Args>
auto parse(istream& is) {
    tuple<Args...> t;
    apply([&is](auto&&... args) {((is >> args), ...);}, t);
    return t;
}

int main() {
    BankAgency bank;
    while (true) {
        try {
            std::string line{}, cmd{};
            std::getline(std::cin >> std::ws, line);
            std::stringstream ss{line};
            ss >> cmd;
        } catch (std::runtime_error& e) {
            std::cout << e.what() << '\n';
        }
    }
}