#include <iostream>
#include "paciente.hpp"
#include "medico.hpp"

int main() {
    auto p1 = new Paciente("L", "avc");
    auto m1 = new Medico("J", "asdf");
    auto m2 = new Medico("K", "asdf");
    std::cout << *m1 << '\n';
    try {
        m1->add_paciente(p1);
        m1->add_paciente(p1);

    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << *m1 << '\n';
    delete m1;
    delete m2;
    delete p1;
}