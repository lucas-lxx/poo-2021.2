#include <iostream>
#include <memory>
#include <vector>
#include "../contato-@014/contact.hpp"
#include "agenda.hpp"

int main() {
    Fone fone{"oi", "1234"};
    Fone fone2{"tim", "0897"};
    std::vector<Fone> fones{fone, fone2};
    Fone fone12{"oi", "122"};
    Fone fone22{"tim", "4334"};
    Fone fone32{"claro", "2323"};
    std::vector<Fone> fones2{fone12, fone22, fone32};
    Agenda agenda;
    agenda.addContact("Lucas", fones);
    agenda.addContact("Norma", fones2);
    std::cout << agenda;
    std::cout << "----\n";
    Fone fone0{"zero", "0000"};
    std::vector<Fone>asdf{fone0};
    agenda.addContact("Lucas", asdf);
    std::cout << agenda;
}