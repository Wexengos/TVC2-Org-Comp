#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "IDStage.h"
//#include <cstdint>

IDStage::IDStage() {}

int32_t IDStage::binaryToDecimal(string input)
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

void IDStage::getOpcode(string input)
{
    string aux;
    for (int i = 0; i < 6; i++)
    {
        aux += input[i];
    }

    cout << "imprime o cabuloso " << aux << endl;

    if (opcode == 0)
        this->type = "R";
    else if (opcode == 2 || opcode == 3)
        this->type = "J";
    else if (opcode >= 5 || opcode <= 43)
        this->type = "I";
    else
        this->type = "ERROR";
}
