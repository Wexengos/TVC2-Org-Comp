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
    void addi(Word res, Word a0, Word a1);
    void lw(Word res, Word a0, Word a1);
    void sw(Word res, Word a0, Word a1);
    void beq(Word res, Word a0, Word a1);
    void bne(Word res, Word a0, Word a1);
};