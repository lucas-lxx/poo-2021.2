#include "medico.hpp"
#include "paciente.hpp"
#include <iostream>
#include <map>

Medico::Medico(std::string id = "", std::string classe = ""):
    classe(classe), id(id) {
}

void Medico::add_paciente(IPaciente* paciente) {
    // boolean is true when insert operation is successful
    auto [paciente_it, boolean] = pacientes.insert({paciente->get_id(), paciente});
    if (boolean)
        paciente->add_medico(this);
}

std::string Medico::get_classe() {
    return this->classe;
}

std::string Medico::get_id() {
    return this->id;
}

std::map<std::string, IPaciente*> Medico::get_pacientes() {
    return this->pacientes;
}

void Medico::remover_paciente(std::string id_paciente) {
    auto it_paciente = this->pacientes.find(id_paciente);
    if (it_paciente == this->pacientes.end())
        return;
    auto paciente = it_paciente->second;
    this->pacientes.erase(it_paciente);
    paciente->remover_medico(this->id);
}

std::ostream& operator<<(std::ostream& os, Medico medico) {
    int size = 20;
    os << "Med: " << medico.id << ":" << medico.classe;
    size = size - (medico.id.size() + medico.classe.size());
    for (int i = 0; i < size; i++)
        os << " ";
    os << "Pacs: [ ";
    for (auto [key, doc] : medico.pacientes)
        os << doc->get_id() << " ";
    os << "]";
    return os;
}