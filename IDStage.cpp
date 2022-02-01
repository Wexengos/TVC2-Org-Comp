#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "IDStage.h"
//#include <cstdint>

IDStage::IDStage() {}

void IDStage::binaryToDecimal(string input, string auxFunct)
{
    unsigned long dec = 0;
    unsigned long dec2 = 0;
    int i = 0;
    int j = 0;
    int s, s2;

    s = input.size();
    s2 = input.size();
    cout << "pintinho: " << auxFunct << endl;
    while (s--)
    {
        if (input[s] == '0' || input[s] == '1')
        {
            dec = dec + pow(2, i++) * (input[s] - '0');
        }
    };
    while (s2--)
    {
        if (auxFunct[s2] == '0' || auxFunct[s2] == '1')
        {
            dec2 = dec2 + pow(2, j++) * (auxFunct[s2] - '0');
        }
    }

    cout << "\nEquivalente decimal do numero binario: " << dec << "||" << dec2 << endl;

    this->opcode = dec;
    this->function = dec2;
}

string IDStage::binToType(string input)
{
    string auxOp, auxFunct;

    for (int i = 0; i < 6; i++)
    {
        auxOp += input[i];
    }

    for (int s = 26; s < 32; s++)
    {

        auxFunct += input[s];
    }

    this->binaryToDecimal(auxOp, auxFunct);

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
