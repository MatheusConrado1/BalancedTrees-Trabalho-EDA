#ifndef READDATA_H
#define READDATA_H
#include <fstream>
#include <vector>
#include "date.h"
#include "pessoa.h"
#include "avl.h"

std::vector<Pessoa> ler_data() {
    std::fstream file;

    file.open("data.csv", std::ios::in);
    if(!file.is_open()){
        std::cout << "Erro ao abrir o arquivo" << std::endl;
        exit(1);
    }
    //ler cada linha, separar os dados e armazenar em um vetor de pessoas
    //criar um objeto pessoa com os dados da linha
    //inserir o objeto no vector
    //deletar o objeto
    //repetir até o fim do arquivo
    //NationalID,GivenName,Surname,Birthday,City
    
    std::string linha;
    getline(file, linha);   //pular a primeira linha
    std::vector<Pessoa> lista;

    while(!file.eof()){
        Pessoa *aux = new Pessoa();

        getline(file, linha, ',');
        aux->set_cpf(linha);
        getline(file, linha, ',');
        std::stringstream nome_p;
        nome_p << linha;
        getline(file, linha, ',');
        std::stringstream nome_s;
        nome_s << linha;
        std::string nome_completo;
        nome_completo = nome_p.str() + " " + nome_s.str();
        aux->set_nome(nome_completo);
        getline(file, linha, ',');
        aux->set_data_nasc(linha);
        getline(file, linha, '\n');
        aux->set_cidade(linha); 

        //aux->print();

        lista.push_back(*aux);
        delete aux;

    }
    file.close();
    return lista;
}

#endif