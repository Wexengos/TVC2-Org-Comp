#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "J_instructions.h"

J_instructions::J_instructions() {}

J_instructions::~J_instructions() {}

void J_instructions::j(Word *res, Word address)
{
    cout << "Pending 'j'" << endl;
};

void J_instructions::jal(Word *res, Word address)
{
    res->i = address.i;
};

void J_instructions::j_type(Word *res, Word address, int function)
{
    switch (function)
    {
    case 32:
        j(res, address);
        break;
    case 43:
        jal(res, address);
        break;

    default:
        break;
    }
}
