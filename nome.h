#ifndef NOME_H
#define NOME_H

#include <iostream>

using namespace std;

class Nome{
private:
    string nome;
public:
    Nome() = default;
    Nome(string nome);
    string get_nome();
    void set_nome(string nome);
    bool operator>(const Nome &n) const;
    bool operator<(const Nome &n) const;
    bool operator==(const Nome &n) const;
    bool operator>=(const Nome &n) const;
    operator string() const;
    ~Nome();

    friend ostream& operator<<(ostream& os, const Nome& nome);
};

Nome::Nome(string nome) {
    set_nome(nome);
}

string Nome::get_nome() {
    return nome;
}

void Nome::set_nome(string nome) {
    this->nome = nome;
}

bool Nome::operator>(const Nome &n) const {
    return nome > n.nome;
}

bool Nome::operator<(const Nome &n) const {
    return nome < n.nome;
}

bool Nome::operator==(const Nome &n) const {    // operador sobrecarregado ja pensando na busca por prefixo
    // retorna true se n é prefixo de nome
    if (n.nome.size() > nome.size()) {
        return false;
    }
    for (int i = 0; i < (int) n.nome.size(); i++) {
        if (nome[i] != n.nome[i]) {
            return false;
        }
    }
    return true;
}

bool Nome::operator>=(const Nome &n) const {
    return nome >= n.nome;
}

Nome::operator string() const {
    return nome;
}

Nome::~Nome() {
}

ostream& operator<<(ostream& os, const Nome& nome) {    // operador sobrecarregado para imprimir nome
    os << nome.nome;
    return os;
}

#endif