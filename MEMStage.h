#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include "InfoInst.h"
using namespace std;

class MEMStage
{
private:
    InfoInst info;
    bitset<32> result_Alu;
    bitset<5> rs;
    bitset<5> rt;
    bitset<5> address;
    bool mem_read, mem_write, reg_write;
    bool executed, firstExecuted;

public:
    MEMStage()
    {
        executed = false;
        firstExecuted = false;
    };
    ~MEMStage(){};
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