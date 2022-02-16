#include <iostream>
#include "paciente.hpp"
#include "medico.hpp"

int main() {
    auto p1 = new Paciente("L", "avc");
    auto m1 = new Medico("J", "asdf");
    auto m2 = new Medico("K", "asdf");
    std::cout << *p1 << '\n';
    try {
        p1->add_medico(m1);
        std::cout << *p1 << '\n';
        p1->remover_medico(m1->get_id());
        std::cout << *p1 << '\n';

    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    
    // std::cout << *m2 << '\n';
    std::cout << *p1 << '\n';
    delete m1;
    delete m2;
    delete p1;
}