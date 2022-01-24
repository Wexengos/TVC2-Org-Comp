#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
//#include <cstdint>
#include "Fetch.h"

Fetch::Fetch() {}

int32_t Fetch::binaryToDecimal(string input)
{
    unsigned long dec = 0;
    int i = 0;
    int s;

    s = input.size();

    while (s--)
    {
        if (input[s] == '0' || input[s] == '1')
        {
            dec = dec + pow(2, i++) * (input[s] - '0');
        }
    };

    cout << "\nEquivalente decimal do número binario: " << dec << endl;
    return dec;
}

int32_t Fetch::getOpcode(string input)
{
    string aux;
    for (int i = 0; i < 6; i++)
    {
        aux += input[i];
    }

    cout << "imprime o cabuloso " << aux << endl;

    return binaryToDecimal(aux);
}

void Fetch::process(string input)
{
    int32_t opcode = getOpcode(input);

    if (opcode == 0)
        cout << "instrução R" << endl;
    else if (opcode == 2 || opcode == 3)
        cout << "Instrução J" << endl;
    else if (opcode >= 5 || opcode <= 43)
        cout << "Instrução I" << endl;
    else
        cout << "Instrução zoada." << endl;
}