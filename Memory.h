#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Register.h"

using namespace std;

class Memory
{
    private:
        Register *r_alu_result;
        Register *r_store;
        Register *rs;
        Register *rt;
        Register *w_r_addr;

        bool rd_mem;
        bool wrt_mem;
        bool wrt_e;
        bool execute;
        

    public:
        Memory();
        ~Memory();
};