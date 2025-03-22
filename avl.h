#ifndef AVL_H
#define AVL_H
#include <string>
#include "pessoa.h"
#include "date.h"
#include "node.h"

template <typename T>
class avl_tree {
public:
    /* Cabeçalho dos métodos públicos
    void add(T key);
    void add(T key, Pessoa pessoa);
    void search(T key);
    void search(T key, T key2);
    void bshow() const;
    void clear();
    void remove(T key);
    ~avl_tree();
    */
    //Implementação dos métodos públicos
    avl_tree() = default;
    avl_tree(const avl_tree& t) = delete;
    avl_tree& operator=(const avl_tree& t) = delete;
    //add convencional
    void add(T key) {
        root = add(root, key);
    }
    //add que ja adiciona o no atualizando o ponteiro toPerson
    void add(T key, Pessoa *pessoa) {
        root = addToPerson(root, key, pessoa);
    }

    //search com 1 parametro
    void search(T key){
        search(root, key);
    }
    //search com 2 parametros
    void search(T key, T key2){
        search(root, key, key2);
    }

    void bshow() const {
        bshow(root, "");
    }

    void clear() {
        root = clear(root);
    }
    
    void remove(T key) {
        root = remove(root, key);
    }

    ~avl_tree() {
        clear();
    }
 
private:
    /* Cabeçalho dos métodos privados
    int height(Node *node);
    int balance(Node *node);
    Node* rightRotation(Node *p);
    Node* leftRotation(Node *p);
    Node* add(Node *p, T key);
    Node* addtoPerson(Node *p, Pessoa pessoa);
    Node* search(Node *p, T key);
    Node* search(Node *p, T key, T key2);
    Node* fixup_node(Node *p, T key);
    void bshow(Node *node, std::string heranca) const;
    Node* clear(Node *node);
    Node* remove(Node *node, T key); 
    Node* remove_successor(Node *root, Node *node);
    Node* fixup_deletion(Node *node);
    */

    // Implementação dos métodos privados
    Node<T> *root {nullptr};

    int height(Node<T> *node) {
        if(node == nullptr)
            return 0;
        return node->height;
    }

    int balance (Node<T> *node) {
        return height(node->right) - height(node->left);
    }

    Node<T>* rightRotation(Node<T> *p) {
        Node<T> *u = p->left;
        p->left = u->right;
        u->right = p;
        // recalcular as alturas de p e de u
        p->height = 1 + std::max(height(p->left),height(p->right));
        u->height = 1 + std::max(height(u->left),height(u->right));
        return u;
    }

    
    Node<T>* leftRotation(Node<T> *p) {
        Node<T> *u = p->right;
        p->right = u->left;
        u->left = p;
        // recalcular as alturas de p e de u
        p->height = 1 + std::max(height(p->right),height(p->left));
        u->height = 1 + std::max(height(u->left),height(u->right));
        return u;
    }
    //faz a operacao comum de adicionar um no, mas tambem adicionando o ponteiro do person
    Node<T>* addToPerson(Node<T> *p, T key, Pessoa *pessoa) {
        if(p == nullptr)
            return new Node(key, pessoa);
        if(key < p->key)
            p->left = addToPerson(p->left, key, pessoa);
        else 
            p->right = addToPerson(p->right, key, pessoa);

        p = fixup_node(p, key);
        return p;
    }
    //faz a operacao comum de adicionar um no
    Node<T>* add(Node<T> *p, T key) {
        if(p == nullptr){
            //bshow();
            return new Node(key);
        }
        if(key < p->key)
            p->left = add(p->left, key);
        else 
            p->right = add(p->right, key);

        p = fixup_node(p, key);
        return p;
    }
    //search com um parametro, funcional tanto para cpf quanto para nome, la linha 143 ao fazer a comparação, 
    //o == está devidamente sobrecarregado para cada classe
    void search(Node<T> *p, T key){
        if(p == nullptr){       
            return;
        }
        if(p->key == key){              
            Pessoa *aux = p->toPessoa;  
            aux->print();               
        }
        //continua a busca
        search(p->left, key);
        search(p->right, key);
    }
    //search com dois parametros, funcional para intervalo de datas, novamente os operadores estão devidamente sobrecarregados
    void search(Node<T> *p, T key, T key2){
        if(p == nullptr){               
            return;
        }
        if(p->key >= key && p->key <= key2){    
            Pessoa *aux = p->toPessoa;          
            aux->print();                       
        }
        //continua a busca
        search(p->left, key, key2);
        search(p->right, key, key2);
    }

    Node<T>* fixup_node(Node<T> *p, T key) {
        // recalcula a altura de p
        p->height = 1 + std::max(height(p->left),height(p->right));
    
        // calcula o balanço do p
        int bal = balance(p);

        if(bal >= -1 && bal <= 1) {
            return p;
        }

        if(bal < -1 && key < p->left->key) {
            p = rightRotation(p);
        }
        else if(bal < -1 && key > p->left->key) {
            p->left = leftRotation(p->left);
            p = rightRotation(p);
        }
        else if(bal > 1 && key > p->right->key) {
            p = leftRotation(p);
        }
        else if(bal > 1 && key < p->right->key) {
            p->right = rightRotation(p->right);
            p = leftRotation(p);
        }
        return p;
    }

    void bshow(Node<T> *node, std::string heranca) const {
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            bshow(node->right , heranca + "r");
        for(int i = 0; i < (int) heranca.size() - 1; i++)
            std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
        if(heranca != "")
            std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
        if(node == nullptr){
            std::cout << "#" << std::endl;
            return;
        }
        std::cout << node->key << std::endl;
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            bshow(node->left, heranca + "l");
    }

   
    Node<T>* clear(Node<T> *node) {
        if(node != nullptr) {
            node->left = clear(node->left);
            node->right = clear(node->right);
            delete node;
        }
        return nullptr;
    }

    Node<T>* remove(Node<T> *node, T key) {
        if(node == nullptr) // node nao encontrado
            return nullptr; 
        if(key < node->key) 
            node->left = remove(node->left, key);
        else if(key > node->key)
            node->right = remove(node->right, key);
        // encontramos no node
        else if(node->right == nullptr) { // sem filho direito
            Node<T> *child = node->left;
            delete node;
            return child;
        }
        else // tem filho direito: troca pelo sucessor
            node->right = remove_successor(node, node->right); /*L\pauseL*/
        
        // Atualiza a altura do node e regula o node
        node = fixup_deletion(node); 
        return node;
    }
    
    Node<T>* remove_successor(Node<T> *root, Node<T> *node) {
        if(node->left != nullptr)
            node->left = remove_successor(root, node->left);
        else {
            root->key = node->key;
            Node<T> *aux = node->right;
            delete node;
            return aux;
        }
        // Atualiza a altura do node e regula o node
        node = fixup_deletion(node);
        return node;
    }

    Node<T>* fixup_deletion(Node<T> *node) {
        node->height = 1 + std::max(height(node->left),height(node->right));

        int bal = balance(node);

        // node pode estar desregulado, ha 4 casos a considerar
        if(bal > 1 && balance(node->right) >= 0) {
            return leftRotation(node);
        }
        else if(bal > 1 && balance(node->right) < 0) {
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }
        else if(bal < -1 && balance(node->left) <= 0) {
            return rightRotation(node);
        }
        else if(bal < -1 && balance(node->left) > 0) { 
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
        return node;
    }
};

#endif