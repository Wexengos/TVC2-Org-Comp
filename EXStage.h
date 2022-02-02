#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

class EXStage
{
private:
    bool type_i, mem_read, mem_write, reg_write;
    bool executed, firstExecuted;

    bitset<5> rs;
    bitset<5> rt;
    bitset<32> reg1;
    bitset<32> reg2;
    bitset<16> Immediate;
    bitset<2> alu_op;

public:
    EXStage();
    ~EXStage();
    bool getExecuted()
    {
        return executed;
    };
    void setExecuted(bool val)
    {
        executed = val;
    };
    
    bool getFirstExecuted()
    {
        return firstExecuted;
    };
    void setFirstExecuted(bool val)
    {
        firstExecuted = val;
    };
};
