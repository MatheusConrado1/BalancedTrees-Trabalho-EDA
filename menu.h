#include <iostream>
#include <iomanip>
using namespace std;

void print_main_menu(){
    cout << "┌─────────────────────────────────────────────────┐"    << endl;
    cout << "│                Menu Principal                   │"    << endl;
    cout << "│                                                 │"    << endl;
    cout << "│  1. Imprimir as arvores                         │"    << endl;
    cout << "│  2. Buscar por CPF                              │"    << endl;
    cout << "│  3. Buscar por nome                             │"    << endl;
    cout << "│  4. Buscar por intervalo de data de nascimento  │"    << endl;
    cout << "│  5. Sair                                        │"    << endl;
    cout << "│                                                 │"    << endl;
    cout << "└─────────────────────────────────────────────────┘"    << endl;
}

void print_menu_arvores(){
    cout << "┌─────────────────────────────────────────────────┐"    << endl;
    cout << "│                Menu Arvores                     │"    << endl;
    cout << "│                                                 │"    << endl;
    cout << "│  1. Arvore de CPF                               │"    << endl;
    cout << "│  2. Arvore de Nome                              │"    << endl;
    cout << "│  3. Arvore de Data de Nascimento                │"    << endl;
    cout << "│  4. Voltar ao menu principal                    │"    << endl;
    cout << "│                                                 │"    << endl;
    cout << "└─────────────────────────────────────────────────┘"    << endl;
}

void print_final(){
    cout << "┌─────────────────────────────────────────────────┐"    << endl;
    cout << "│                                                 │"    << endl;
    cout << "│  Programa encerrado!                            │"    << endl;
    cout << "│                                                 │"    << endl;
    cout << "│  UFC - Campus Quixadá                           │"    << endl;
    cout << "│  Projeto de EDA - 2023.1                        │"    << endl;
    cout << "│  Implementação de árvores balanceadas           │"    << endl;
    cout << "│  Aluno: Matheus Conrado Pires                   │"    << endl;
    cout << "│  Professor: Atílio Gomes Luiz                   │"    << endl;
    cout << "│                                                 │"    << endl;
    cout << "└─────────────────────────────────────────────────┘"    << endl;
}

void s_pause(){
    string lixo;
    cout << endl;
    cout << "Pressione qualquer tecla para continuar..." << endl;
    cin >> lixo;
    system("cls||clear");
}