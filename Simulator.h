#ifndef Simulator_H
#define Simulator_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
//#include <cstdint>
#include "Registers.h"
#include "IFStage.h"
#include "IDStage.h"
#include "EXStage.h"
#include "MEMStage.h"
#include "WBStage.h"

using namespace std;

class Simulator
{
private:
    IFStage *IF;
    IDStage *ID;
    EXStage *EX;
    MEMStage *MEM;
    WBStage *WB;

    int PC, cycle;
    Registers **registers;
    bitset<32> memory[512];
    bitset<32> memory_data[512];

    bool PC_left;
    bool isIFStage, isIDStage, isEXStage, isMEMStage, isWBStage;

public:
    Simulator();
    ~Simulator(){};

    void exec(string input);
    void IFStageExec(string input);
    void IDStageExec();
    void EXStageExec();
    void MEMStageExec();
    void WBStageExec();
    void setRegisters();
    void printRegisters();

    void setReg(int i, Registers *r) { registers[i] = r; };
    void setRegValue(int i, bitset<32> val) { registers[i]->setValue(val); };
    Registers *getReg(int i) { return registers[i]; };
};

#endif