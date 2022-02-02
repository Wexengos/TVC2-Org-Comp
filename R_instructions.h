#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
// add, sub, and, or, slt

class R_instructions
{
private:
public:
    R_instructions();
    ~R_instructions();
    string r_type(int function);
};