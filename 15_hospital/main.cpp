#include <iostream>
#include <vector>
#include "../cpp-functional/auxiliar.hpp"
#include "paciente.hpp"
#include "medico.hpp"
#include "hospital.hpp"

int main() {
    Hospital hospital;
    
    while (true) {
        std::string line;
        // std::cout << "$ ";
        std::getline(std::cin >> std::ws, line);
        std::cout << "$" << line << '\n';
        std::vector<std::string> command {aux::split(line, ' ')};
        try {
            if (command[0] == "end") {
                break;
            } else if (command[0] == "addPacs") {
                auto pacs = aux::slice(command, 1);
                for (auto i:pacs)
                    hospital.add_paciente(std::make_shared<Paciente>(aux::split(i, '-')[0], aux::split(i, '-')[1]));
            } else if (command[0] == "show") {
                std::cout << hospital;
            } else if (command[0] == "addMeds") {
                auto pacs = aux::slice(command, 1);
                for (auto i:pacs)
                    hospital.add_medico(std::make_shared<Medico>(aux::split(i, '-')[0], aux::split(i, '-')[1]));
            } else if (command[0] == "tie") {
                auto pacs = aux::slice(command, 2);
                for (auto i:pacs)
                    hospital.vincular(command[1], i);
            }
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    
}