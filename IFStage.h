#ifndef IF_H
#define IF_HP

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#include "InfoInst.h"

using namespace std;

class IFStage
{
private:
    bitset<32> PC;
    string instruction;
    bool executed;

public:
    IFStage()
    {
        executed = false;
        instruction = "";
    };
    ~IFStage();
    void setInstruction(string input)
    {
        instruction = input;
    };
    string getInstruction() { return instruction; };

    void setPC(int value) { PC = value; };
    bitset<32> getPC() { return PC; };

    bool getExecuted() { return executed; };
    void setExecuted(bool val) { executed = val; };
};

#endif