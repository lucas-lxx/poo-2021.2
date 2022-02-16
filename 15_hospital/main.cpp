#include <iostream>
#include "paciente.hpp"
#include "medico.hpp"
#include "hospital.hpp"

int main() {
    Hospital hospital;
    auto p1 = new Paciente("L", "avc");
    auto m1 = new Medico("J", "asdf");
    auto m2 = new Medico("K", "asdf");
    std::cout << *p1 << '\n';
    try {
        hospital.add_medico(m1);
        hospital.add_medico(m2);
        hospital.add_paciente(p1);
        hospital.vincular(m1->get_id(), p1->get_id());
        std::cout << *m1 << '\n';
        std::cout << *p1 << '\n';
        hospital.vincular(m2->get_id(), p1->get_id());

    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    
    std::cout << *m1 << '\n';
    std::cout << *p1 << '\n';
    delete m1;
    delete m2;
    delete p1;
}