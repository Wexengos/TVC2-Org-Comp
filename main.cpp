
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Função de de ler arquivo*/
void read_txt(string &s)
{
    ifstream arq("input.txt");

    if (arq.is_open())
    {

        string str;
        int count = 1;

        while (getline(arq, str))
        {
            count++;
        }

        s = str;
    }
    else
        cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;
}

void menu()
{
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
        cout << "Etapa 1" << endl;
        break;

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

int main(void)
{
    string str;
    menu();
}