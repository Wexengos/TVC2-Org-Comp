#ifndef Simulator_H
#define Simulator_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
//#include <cstdint>
#include "IFStage.h"
#include "IDStage.h"
#include "EXStage.h"
#include "WBStage.h"
#include "Memory.h"
#include "Registers.h"

using namespace std;

class Simulator
{
private:
    IFStage *IF;
    IDStage *ID;
    EXStage *EX;
    WBStage *WB;

    // Array de Registradores
    Registers **registers;
    Memory **memory;

    int PC;

public:
    Simulator();
    ~Simulator(){};

    void exec(string input);
    void IFStageExec(string input);
    void IDStageExec();
    void setRegisters();

    void setReg(int i, Registers *r) { registers[i] = r; };
    Registers *getReg(int i) { return registers[i]; };
};

#endif