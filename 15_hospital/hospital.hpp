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
        auto medico = get_medico_iterator(id_medico)->second;
        auto paciente = get_paciente_iterator(id_paciente)->second;
        check_pacients_list(medico, id_paciente);
        check_doctors_list(paciente, medico);
        medico->add_paciente(paciente);
    }

private:
    void check_pacients_list(IMedico* medico, std::string id_paciente) {
        auto check = medico->get_pacientes().find(id_paciente);
        if (check != medico->get_pacientes().end())
            throw std::runtime_error("fail: pacient already on the list");
    }

    void check_doctors_list(IPaciente* paciente, IMedico* medico) {
        for (auto it_medico:paciente->get_medicos()){
            if (it_medico.second->get_classe() == medico->get_classe())
                throw std::runtime_error("fail: there is already a doctor with that expertise on atendece");
        }
    }

    std::map<std::string, IMedico*>::iterator get_medico_iterator(std::string id_medico) {
        auto it_medico = medicos.find(id_medico);
        if (it_medico == medicos.end())
            throw std::runtime_error("fail: doctor not found");
        return it_medico;
    }

    std::map<std::string, IPaciente*>::iterator get_paciente_iterator(std::string id_paciente) {
        auto it_paciente = pacientes.find(id_paciente);
        if (it_paciente == pacientes.end())
            throw std::runtime_error("fail: pacient not found");
        return it_paciente;
    }

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