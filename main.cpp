#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Simulator.h"

using namespace std;

/* Função de de ler arquivo*/
void read_txt(vector<string> &s)
{
    cout << "COMEÇOU - lendo arquivo " << endl;
    ifstream arq("input.txt");

    if (arq.is_open())
    {

        string str;
        int count = 0;

        while (getline(arq, str))
        {
            s.push_back(str);
            cout << "Instrucao numero " << count << ": " << s[count] << endl;
            count++;
        }
    }
    else
        cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;

    cout << "FECHOU " << endl;
}

void menu()
{
    vector<string> instructions;

    int menu;
    cout << "====================MENU PRINCIPAL====================" << endl;
    cout << "Digite:" << endl;
    cout << "[1] Entrada via arquivo" << endl;
    cout << "[2] Entrada via teclado" << endl;
    cout << "[3] Execucao" << endl;
    cout << "[4] Reset" << endl;
    cout << "[5] Fechar" << endl;
    cin >> menu;

    switch (menu)
    {
    case 1:
    {
        cout << "Etapa 1" << endl;
        read_txt(instructions);

        for (int i = 0; i < instructions.size(); i++)
        {
            Simulator *MIPS = new Simulator();  // nova instância para o Pipeline do simulador

            cout << "VAI EXECUTAR O " << instructions[i] << endl;
            MIPS->exec(instructions[i]);
        };
        break;
    }

    case 2:

        cout << "Etapa 2" << endl;

        break;

    case 3:

        cout << "Etapa 3" << endl;
        break;

    case 4:

        cout << "Etapa 4" << endl;
        break;
    case 5:
        cout << "Fechando Exec!" << endl;
        //exit(1);
        break;

    default:
        cout << "Valor invalido" << endl;
        break;
    }
    cout << "Fim" << endl;
}

int main(int argc, char *argv[])
{
    menu();

    return 0;
}