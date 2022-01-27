#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Register.h"

using namespace std;

class WBStage
{
    private:
        Register *r_alu_result;
        Register *rs;
        Register *rt;
        Register *w_r_addr;

        bool wrt_e;
        bool execute;
        

    public:
        WBStage();
        ~WBStage();
};