#ifndef PACIENTE_HPP
#define PACIENTE_HPP
#include <iostream>
#include <map>

class IMedico;

class IPaciente {
public:
    virtual ~IPaciente() {};

    virtual void add_medico(IMedico*) = 0;

    virtual std::string get_diagnostico() = 0;

    virtual std::string get_id() = 0;

    virtual std::map<std::string, IMedico*> get_medicos() = 0;

    virtual void remover_medico(std::string) = 0;

};

class Paciente : public IPaciente {
public:
    Paciente(std::string, std::string);

    virtual void add_medico(IMedico*);

    virtual std::string get_diagnostico();

    virtual std::string get_id();

    virtual std::map<std::string, IMedico*> get_medicos();

    virtual void remover_medico(std::string);

    friend std::ostream& operator<<(std::ostream&, Paciente);

private:

    std::string id;
    std::string diagnostico;
    std::map<std::string, IMedico*> medicos;

};

#endif