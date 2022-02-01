#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "IDStage.h"
//#include <cstdint>

IDStage::IDStage() {}

void IDStage::binaryToDecimal(string input, string auxFunct, string auxRs, string auxRd, string auxRt)
{
    unsigned long dec = 0;
    unsigned long dec2 = 0;
    unsigned long dec3 = 0;
    unsigned long dec4 = 0;
    unsigned long dec5 = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int n = 0;
    int l = 0;
    int s;

    s = input.size();

    cout << "pintinho: " << auxFunct << endl;
    while (s--)
    {
        if (input[s] == '0' || input[s] == '1')
        {
            dec = dec + pow(2, i++) * (input[s] - '0');
        }

        if (auxFunct[s] == '0' || auxFunct[s] == '1')
        {
            dec2 = dec2 + pow(2, j++) * (auxFunct[s] - '0');
        }

        if (auxRs[s] == '0' || auxRs[s] == '1')
        {
            dec3 = dec3 + pow(2, l++) * (auxRs[s] - '0');
        }

        if (auxRd[s] == '0' || auxRd[s] == '1')
        {
            dec4 = dec4 + pow(2, m++) * (auxRd[s] - '0');
        }

        if (auxRt[s] == '0' || auxRt[s] == '1')
        {
            dec5 = dec5 + pow(2, n++) * (auxRt[s] - '0');
        }
    };

    cout << "\nEquivalente decimal do numero binario: " << dec << "|| " << dec2 << "|| " << dec3 << "|| " << dec4 << endl;

    this->opcode = dec;
    this->function = dec2;
    cout << "A1" << endl;
    this->rs = dec3;
    cout << "A2" << endl;
    this->rd = dec4;
    cout << "A3" << endl;
}

char IDStage::binToType(string input)
{
    string auxOp, auxFunct, auxRs, auxRd, auxRt;

    for (int i = 0; i < 6; i++)
    {
        auxOp += input[i];
    }

    for (int i = 6; i < 11; i++)
    {
        auxRs += input[i];
    }

    for (int i = 11; i < 16; i++)
    {
        auxRt += input[i];
    }

    for (int i = 16; i < 21; i++)
    {
        auxRd += input[i];
    }

    for (int s = 26; s < 32; s++)
    {

        auxFunct += input[s];
    }

    this->binaryToDecimal(auxOp, auxFunct, auxRs, auxRt, auxRd);
    cout << "aqui";
    if (this->opcode == 0)
    {
        this->type = 'R';
        return 'R';
    }
    else if (opcode == 2 || opcode == 3)
    {
        this->type = 'J';
        return 'J';
    }
    else if (opcode >= 5 || opcode <= 43)
    {

        this->type = 'I';

        return 'I';
    }
    else
    {
        this->type = 'E';
        return 'E';
    }
}
