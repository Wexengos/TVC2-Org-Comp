#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "IDStage.h"
//#include <cstdint>

IDStage::IDStage() {}

void IDStage::binaryToDecimal(string input)
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

    cout << "\nEquivalente decimal do numero binario: " << dec << endl;

    this->opcode = dec;

    cout << opcode;
}

string IDStage::binToType(string input)
{
    string aux;
    for (int i = 0; i < 6; i++)
    {
        aux += input[i];
    }

    this->binaryToDecimal(aux);

    if (this->opcode == 0)
    {
        this->type = "R";
        return "R";
    }
    else if (opcode == 2 || opcode == 3)
    {
        this->type = "J";
        return "J";
    }
    else if (opcode >= 5 || opcode <= 43)
    {
        this->type = "I";
        return "I";
    }
    else
    {
        this->type = "ERROR";
        return "ERROR";
    }
}
