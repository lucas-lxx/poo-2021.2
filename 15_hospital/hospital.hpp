#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP
#include <iostream>
#include <map>
#include "medico.hpp"
#include "paciente.hpp"

class Hospital {
public:
    Hospital() {};

    void add_medico(IMedico* medico) {
        auto [medico_it, boolean] = this->medicos.insert({medico->get_id(), medico});
        if (!boolean)
            throw std::runtime_error("fail: there is already a doctor with this id");
    }


    void add_paciente(IPaciente* paciente) {
        auto [paciente_it, boolean] = this->pacientes.insert({paciente->get_id(), paciente});
        if (!boolean)
            throw std::runtime_error("fail: there is already a pacient with this id");
    }

    void remover_medico(std::string id_medico) {
        auto it_medico = this->medicos.find(id_medico);
        if (it_medico == this->medicos.end())
            throw std::runtime_error("fail: this doctor does not exist");
        auto medico = it_medico->second;
        remover_todos_os_pacientes(medico);
        this->medicos.erase(it_medico);
    }

    void remover_paciente(std::string id_paciente) {
        auto it_paciente = this->pacientes.find(id_paciente);
        if (it_paciente == this->pacientes.end())
            throw std::runtime_error("fail: this pacient does not exist");
        auto paciente = it_paciente->second;
        remover_todos_os_medicos(paciente);
        this->pacientes.erase(it_paciente);
    }

    void vincular(std::string id_medico, std::string id_paciente) {
        
    }

private:
    void remover_todos_os_pacientes(IMedico* medico) {
        for (auto [key, pac] : medico->get_pacientes())
            medico->remover_paciente(key);
    }

    void remover_todos_os_medicos(IPaciente* paciente) {
        for (auto [key, doc] : paciente->get_medicos())
            paciente->remover_medico(key);
    }

    std::map<std::string, IMedico*> medicos;
    std::map<std::string, IPaciente*> pacientes;

};

#endif