#ifndef I_INSTRUCTIONS_H
#define I_INSTRUCTIONS_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Word.hpp"

using namespace std;
// addi, lw, sw, beq, bne

class I_instructions
{
private:
public:
    I_instructions();
    ~I_instructions();
    string i_type(int opcode);
};

#endif