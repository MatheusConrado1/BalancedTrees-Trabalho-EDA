#include <iostream>
#include "avl.h"
#include "readData.h"
#include "menu.h"
using namespace std;

//Projeto de Estrutura de Dados Avançada -- Implementação de árvores balanceadas
//Aluno: Matheus Conrado Pires - 536536
//Professor: Atílio Gomes Luiz
//UFC - Campus Quixadá - 2023.1 

int main() {
    // Ler os dados do arquivo
    vector<Pessoa> Lista = ler_data();
    
    // Criar as árvores a partir dos dados
    avl_tree<CPF> *tCPF = new avl_tree<CPF>();
    for(int i = 0; i < (int) Lista.size(); i++){
        tCPF->add(Lista[i].cpf, &Lista[i]);
    }

    avl_tree<Nome> *tNOME = new avl_tree<Nome>();
    for(int i = 0; i < (int) Lista.size(); i++){
        tNOME->add(Lista[i].get_nome(), &Lista[i]);
    }

    avl_tree<date> *tDATA = new avl_tree<date>();
    for(int i = 0; i < (int) Lista.size(); i++){
        tDATA->add(Lista[i].get_data_nasc(), &Lista[i]);
    }
    // Menu principal
    do{
        print_main_menu();
        int entry;
        cin >> entry;
        system("cls||clear");
        if(entry == 1){     // Imprimir as árvores
            do{
                print_menu_arvores();
                int entry2;
                cin >> entry2;
                system("cls||clear");
                if(entry2 == 1){
                    tCPF->bshow();
                    s_pause();
                } else
                if(entry2 == 2){
                    tNOME->bshow();
                    s_pause();
                } else
                if(entry2 == 3){
                    tDATA->bshow();
                    s_pause();
                } else
                if(entry2 == 4){
                    break;
                } else{
                    cout << "Entrada invalida!" << endl;
                }
                system("cls||clear");
            } while(true);
        } else
        if(entry == 2){     // Buscar pessoa por CPF
            string cpf;
            cout << "Digite o CPF xxx.xxx.xxx-xx:" << endl;
            cin >> cpf;
            CPF temp = CPF(cpf);
            tCPF->search(temp);
            s_pause();
        } else
        if(entry == 3){     // Buscar pessoa por nome
            string nome;
            cout << "Digite o nome: ";
            cin >> nome;
            Nome temp = Nome(nome);
            tNOME->search(temp);
            s_pause();
        } else
        if(entry == 4){     // Buscar pessoa por intervalo de data de nascimento
            string data1, data2;
            cout << "Digite a data inicial (mm/dd/aaaa): " << endl;
            cin >> data1;
            cout << "Digite a data final (mm/dd/aaaa):" << endl;
            cin >> data2;
            tDATA->search(date(data1), date(data2));
            s_pause();
        } else
        if(entry == 5){     // Sair
            break;
        } else{             
            cout << "Entrada invalida!" << endl;
        }
        system("cls||clear");
    }while(1);

    //deletar as arvores
    delete tCPF;
    delete tNOME;
    delete tDATA;

    print_final();

    return 0;
}