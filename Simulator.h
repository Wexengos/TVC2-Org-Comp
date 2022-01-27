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
#include "Register.h"

using namespace std;

class Simulator
{
private:
    IFStage *IF;
    IDStage *ID;
    EXStage *EX;
    WBStage *WB;
    
    // Array de Registradores
    Register **reg;
    Memory **reg;

public:
    Simulator();
    ~Simulator(){};

    void exec(string input);
    void setRegisters();

    void setReg(int i, Register *r) { reg[i] = r; };
    Register *getReg(int i) { return reg[i]; };
};

#endif