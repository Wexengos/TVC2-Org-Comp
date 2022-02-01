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
    void j(Word res, Word a0, Word a1);
    void jal(Word res, Word a0, Word a1);
};