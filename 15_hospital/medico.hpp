#ifndef MEDICO_HPP
#define MEDICO_HPP
#include <iostream>
#include <map>

class IPaciente;

class IMedico {
public:
    virtual ~IMedico() {};

    virtual void add_paciente(IPaciente*) = 0;

    virtual std::string get_classe() = 0;

    virtual std::string get_id() = 0;

    virtual std::map<std::string, IPaciente*> get_pacientes() = 0;

    virtual void remover_paciente(std::string) = 0;
};

class Medico : public IMedico {
public:
    Medico(std::string sender, std::string classe);

    // virtual void double_patient(IPaciente*);

    virtual void add_paciente(IPaciente* paciente);

    virtual std::string get_classe();

    virtual std::string get_id();

    virtual std::map<std::string, IPaciente*> get_pacientes();

    virtual void remover_paciente(std::string id_paciente);

    friend std::ostream& operator<<(std::ostream& os, Medico medico);

private:
    std::string classe;
    std::map<std::string, IPaciente*> pacientes;
    std::string id;

};

#endif