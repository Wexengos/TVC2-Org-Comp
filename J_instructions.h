
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
    string j_type(int opcode);
};
