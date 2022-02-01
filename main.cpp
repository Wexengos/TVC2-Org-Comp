#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Simulator.h"

using namespace std;

/* Função de de ler arquivo*/
void read_txt(vector<string> &s, string file_name)
{
    cout << "Lendo arquivo..." << endl;
    ifstream arq("input.txt");

    if (arq.is_open())
    {

        string str;
        int count = 0;

        while (getline(arq, str))
        {
            s.push_back(str);
            count++;
        }
    }
    else
        cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;

    cout << "Finalizando Leitura de arquivo." << endl;
}

void menu(vector<string> instructions)
{

    string file_name;
    string instr;

    int menuop;
    cout << "====================MENU PRINCIPAL====================" << endl;
    cout << "Digite:" << endl;
    cout << "[1] Entrada via arquivo" << endl;
    cout << "[2] Entrada via teclado" << endl;
    cout << "[3] Execucao" << endl;
    cout << "[4] Reset" << endl;
    cout << "[5] Fechar" << endl;
    cin >> menuop;

    switch (menuop)
    {
    case 1:
    {
        system("cls");
        cout << "Opção 1" << endl;
        cout << "Digite o nome + formato do arquivo: " << endl;

        cin >> file_name;

        read_txt(instructions, file_name);
        menu(instructions);
        break;
    }

    case 2:
    {
        system("cls");
        int count = 0;

        cout << "Opção 2" << endl;
        cout << "Digite o numero de instrucoes: " << endl;
        cin >> count;
        for (int i = 0; i < count; i++)
        {
            cout << "Digite a sua " << i + 1 << "a instrução." << endl;
            cin >> instr;

            instructions.push_back(instr);
        }

        menu(instructions);
        break;
    }
    case 3:
    {
        int option;
        cout << "Selecione a execução [1] passo a passo ou [2] direta: " << endl;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            for (int i = 0; i < instructions.size(); i++)
            {
                char option1;
                Simulator *MIPS = new Simulator();
                cout << "Instrucao numero " << i << ": " << instructions[i] << endl;
                cout << "Continuar execução? [s/n] " << endl;
                cin >> option1;

                if (option1 != 's')
                {
                    cout << "Finalizando execução... " << endl;
                    break;
                }
                MIPS->exec(instructions[i]);
            }
        }
        case 2:
        {
            for (int i = 0; i < instructions.size(); i++)
            {
                Simulator *MIPS = new Simulator(); // nova instância para o Pipeline do simulador
                cout << "Instrucao numero " << i << ": " << instructions[i] << endl;
                MIPS->exec(instructions[i]);
            };
        }
        }

        cout << "Etapa 3" << endl;
        break;
    }

    case 4:

        cout << "Etapa 4" << endl;
        break;
    case 5:
        cout << "Fechando Exec!" << endl;
        // exit(1);
        break;

    default:
        cout << "Valor invalido" << endl;
        break;
    }
    cout << "Fim" << endl;
}

int main(int argc, char *argv[])
{
    vector<string> instructions;
    menu(instructions);

    return 0;
}