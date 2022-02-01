#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Registers.h"

using namespace std;

class Memory
{
private:
    bool rd_mem;
    bool wrt_mem;
    bool wrt_e;
    bool execute;

public:
    Memory();
    ~Memory();
};