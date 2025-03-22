#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
#include <sstream>
#include "pessoa.h"

template <typename T>
struct Node {
        // atributos
        T key;
        int height;
        Node *left;
        Node *right;
        Pessoa* toPessoa = nullptr;
        // Construtor padrao
        Node (T key) {
            this->key = key;
            this->height = 1;
            this->left = nullptr;
            this->right = nullptr;
        }
        // Construtor que recebe um ponteiro para pessoa
        Node (T key, Pessoa *pessoa) {
            this->key = key;
            this->height = 1;
            this->left = nullptr;
            this->right = nullptr;
            Pessoa aux = *pessoa;
            this->toPessoa = new Pessoa(aux);
        }
};

#endif