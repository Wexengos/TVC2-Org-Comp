#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "R_instructions.h"

R_instructions::R_instructions()
{
}
// EXStage::~EXStage();

string R_instructions::r_type(int function)
{
    switch (function)
    {
    case 32:
        return "add";
        break;
    case 43:
        break;
    case 34:
        return "sub";
        break;
    case 37:
        return "or";
        break;
    case 42:
        return "slt";
        break;
    case 8:
        return "jr";
        break;
    default:
        break;
    }

        return "";
}