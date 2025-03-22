#ifndef CPF_H
#define CPF_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>


class CPF {
private:
    int cpf_comeco;
    int cpf_segundo;
    int cpf_terceiro;
    int cpf_final;
public:
    CPF() = default;
    CPF(std::string cpf);
    void set_cpf(std::string cpf);
    std::string get_cpf();
    bool operator>(const CPF &c) const;
    bool operator<(const CPF &c) const;
    bool operator==(const CPF &c) const;
    bool operator>=(const CPF &c) const;
    operator std::string() const;
    ~CPF();

    friend std::ostream& operator<<(std::ostream& os, const CPF& cpf);
};

CPF::CPF(std::string cpf) {
    set_cpf(cpf);
}

void CPF::set_cpf(std::string cpf) {
    // Pegar uma string cpf e separar em 4 inteiros
    
    std::stringstream ss(cpf);
    std::stringstream aux;
    std::string auxstr;

    getline(ss, auxstr, '.');
    aux << auxstr;
    aux >> cpf_comeco;
    aux.clear();

    getline(ss, auxstr, '.');
    aux << auxstr;
    aux >> cpf_segundo;
    aux.clear();

    getline(ss, auxstr, '-');
    aux << auxstr;
    aux >> cpf_terceiro;
    aux.clear();

    getline(ss, auxstr, '\n');
    aux << auxstr;
    aux >> cpf_final;
    aux.clear();    
}

std::string CPF::get_cpf() {
    // retorna os 4 inteiros transformados em uma string cpf
    std::stringstream ss;
    ss << cpf_comeco << "." << cpf_segundo << "." << cpf_terceiro << "-" << cpf_final;
    return ss.str();
}

bool CPF::operator<(const CPF &c) const {
    if(cpf_comeco < c.cpf_comeco) {
        return true;
    } else if (cpf_comeco > c.cpf_comeco) {
        return false;
    } else {
        if (cpf_segundo < c.cpf_segundo) {
            return true;
        } else if (cpf_segundo > c.cpf_segundo) {
            return false;
        } else {
            if (cpf_terceiro < c.cpf_terceiro) {
                return true;
            } else if (cpf_terceiro > c.cpf_terceiro) {
                return false;
            } else {
                if (cpf_final < c.cpf_final) {
                    return true;
                } else if (cpf_final > c.cpf_final) {
                    return false;
                } else {
                    return false;
                }
            }
        }
    }
}

bool CPF::operator>(const CPF &c) const {
    if (cpf_comeco > c.cpf_comeco) {
        return false;
    } else if (cpf_comeco < c.cpf_comeco) {
        return true;
    } else {
        if (cpf_segundo > c.cpf_segundo) {
            return false;
        } else if (cpf_segundo < c.cpf_segundo) {
            return true;
        } else {
            if (cpf_terceiro > c.cpf_terceiro) {
                return false;
            } else if (cpf_terceiro < c.cpf_terceiro) {
                return true;
            } else {
                if (cpf_final > c.cpf_final) {
                    return false;
                } else if (cpf_final < c.cpf_final) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
}

bool CPF::operator==(const CPF &c) const {
    return (cpf_comeco == c.cpf_comeco && cpf_segundo == c.cpf_segundo && cpf_terceiro == c.cpf_terceiro && cpf_final == c.cpf_final);
}

bool CPF::operator>=(const CPF &c) const {
    return !(*this < c);    
}

CPF::operator std::string() const {     // sobrecarga que permite a conversão de um CPF para string (ex: "string x = cpf")
    std::stringstream ss;
    ss << cpf_comeco << "." << cpf_segundo << "." << cpf_terceiro << "-" << cpf_final;
    return ss.str();
}

CPF::~CPF() {
}

std::ostream& operator<<(std::ostream& os, const CPF& cpf) {    // sobrecarga que permite a impressão de um CPF (ex: "cout << x->cpf")
    os << std::setfill ('0') << std::setw (3) << cpf.cpf_comeco << "." << std::setfill ('0') << std::setw (3) << cpf.cpf_segundo << "." << std::setfill ('0') << std::setw (3) << cpf.cpf_terceiro << "-" << std::setfill ('0') << std::setw (2) << cpf.cpf_final;
    return os;
}

#endif