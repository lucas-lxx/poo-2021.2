#include <iostream>
#include <map>
#include "paciente.hpp"
#include "medico.hpp"


Paciente::Paciente(std::string id = "", std::string diagnostico = ""):
    id(id), diagnostico(diagnostico) {
}

void Paciente::double_expertise(IMedico* medico) {
    for(auto [key, doc] : this->medicos){
        if(medico->get_classe() == doc->get_classe())
            throw std::runtime_error("fail: there is already a doctor with this expertise");
    }
}

void Paciente::add_medico(IMedico* medico) {
    double_expertise(medico);
    // boolean is true when insert operation is successful
    auto [medico_it, boolean] = medicos.insert({medico->get_id(), medico});
    if (boolean)
        medico->add_paciente(this);
}

std::string Paciente::get_diagnostico() {
    return this->diagnostico;
}

std::string Paciente::get_id() {
    return this->id;
}

std::map<std::string, IMedico*> Paciente::get_medicos() {
    return this->medicos;
}

void Paciente::remover_medico(std::string id_medico) {
    auto it_medico = get_medicos().find(id_medico);
    if (it_medico == get_medicos().end())
        return;
    auto medico = it_medico->second;
    get_medicos().erase(it_medico);
    medico->remover_paciente(this->id);
}

std::ostream& operator<<(std::ostream& os, Paciente paciente) {
    int size = 20;
    os << "Pac: " << paciente.id << ":" << paciente.diagnostico;
    size = size - (paciente.id.size() + paciente.diagnostico.size());
    for (int i = 0; i < size; i++)
        os << " ";
    os << "Meds: [ ";
    for (auto [key, doc] : paciente.medicos)
        os << doc->get_id() << " ";
    os << "]";
    return os;
}