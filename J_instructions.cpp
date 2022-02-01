#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "J_instructions.h"
J_instructions::J_instructions()
{
}
string J_instructions::j_type(int opcode)
{
    switch (opcode)
    {
    case 2:
        return "j";
        break;
    case 0:
        return "jr";
        break;

    default:
        break;
    }
}
