#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Word.hpp"

using namespace std;
// add, sub, and, or, slt

class R_instructions
{
private:
public:
    R_instructions();
    ~R_instructions();
    void r_type(Word res, Word a0, Word a1, int function);
    void add(Word res, Word a0, Word a1);
    void sub(Word res, Word a0, Word a1);
    void And(Word res, Word a0, Word a1); // Se for letra minuscula da zika > and é paralavra reservada
    void Or(Word res, Word a0, Word a1);  // Se for letra minuscula da zika > or é paralavra reservada
    void slt(Word res, Word a0, Word a1);
    void jr(Word res, Word a0, Word a1);
};