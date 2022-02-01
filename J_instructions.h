#ifndef J_INSTRUCTIONS_H
#define J_INSTRUCTIONS_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Word.hpp"
using namespace std;
// j, jr, jal.

class J_instructions
{
private:
public:
    J_instructions();
    ~J_instructions();
    void j_type(Word *res, Word address, int function);
    void j(Word *res, Word address);
    void jal(Word *res, Word address);
};

#endif