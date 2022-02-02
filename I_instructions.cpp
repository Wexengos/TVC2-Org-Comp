#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "I_instructions.h"

I_instructions::I_instructions()
{
}

string I_instructions::i_type(int opcode)
{
    switch (opcode)
    {
    case 35:
        return "lw";
        break;
    case 43:
        return "sw";
        break;
    case 4:
        return "beq";
        break;
    case 5:
        return "bne";
        break;
    case 8:
        return "addi";
        break;
    case 2:
        return "addi";
        break;
    default:
        break;
    }

    return "";
};
