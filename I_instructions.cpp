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
        // add(res, a0, a1);
        return "lw";
        break;
    case 43:
        return "sw";
        // sub(res, a0, a1);
        break;
    case 4:
        // Or(res, a0, a1);
        return "beq";
        break;
    case 5:
        // slt(res, a0, a1);
        return "bne";
        break;
    case 8:
        // jr(res, a0, a1);
        return "addi";
        break;
    case 2:
        // jr(res, a0, a1);
        return "addi";
        break;
    default:
        break;
    }
};
