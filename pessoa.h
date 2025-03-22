#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include "date.h"
#include "cpf.h"
#include "nome.h"

class Pessoa: public date, public CPF, public Nome {
public:
    Pessoa() = default;
    Pessoa(Nome nome, CPF cpf, date data_nasc, std::string cidade);
    std::string get_nome();
    CPF get_cpf();
    std::string get_cidade();
    date get_data_nasc();
    void set_data_nasc(date data_nasc);
    void set_nome(Nome nome);
    void set_cpf(CPF cpf);
    void set_cidade(std::string cidade);
    void print();
    
    ~Pessoa();
    CPF cpf;
    friend std::ostream& operator<<(std::ostream& os, const Pessoa& pessoa);
private:
    Nome nome;
    date data_nasc;
    std::string cidade;
};

// Construtor de pessoa
Pessoa::Pessoa(Nome nome, CPF cpf, date data_nasc, std::string cidade) {
    this->nome = nome;
    this->cpf = cpf;
    this->data_nasc = data_nasc;
    this->cidade = cidade;
}

std::string Pessoa::get_nome() {
    return nome;
}

CPF Pessoa::get_cpf() {
    return cpf;
}

date Pessoa::get_data_nasc() {
    return data_nasc;
}

std::string Pessoa::get_cidade() {
    return cidade;
}

void Pessoa::set_data_nasc(date data_nasc) {
    this->data_nasc = data_nasc;
}

void Pessoa::set_nome(Nome nome) {
    this->nome = nome;
}

void Pessoa::set_cpf(CPF cpf) {
    this->cpf = cpf;
}

void Pessoa::set_cidade(std::string cidade) {
    this->cidade = cidade;
}

void Pessoa::print() {
    std::cout << nome << " " << cpf << " " << data_nasc << " " << cidade << std::endl;
}

Pessoa::~Pessoa() {
    //dtor
}

std::ostream& operator<<(std::ostream& os, const Pessoa& pessoa) {      // sobrecarga que permite imprimir um objeto do tipo Pessoa (cout << pessoa)
    os << pessoa.nome << " " << pessoa.cpf << " " << pessoa.data_nasc << " " << pessoa.cidade;
    return os;
}

#endif