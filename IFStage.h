#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "InfoInst.h"

using namespace std;

class IFStage
{
private:
    InfoInst info;
    int nextInstAddr, thisInstAddr;
    string instruction;
    bool execute;

public:
    IFStage();
    ~IFStage();
    void setInstrction(string input) { instruction = input; };
    string GetInstrction() { return instruction; };
    void setNextInstAddr(int value) { nextInstAddr = value; };
    int getNextInstAddr() { return nextInstAddr; };
    void setThisInstAddr(int value) { thisInstAddr = value; };
    int getThisInstAddr() { return thisInstAddr; };
};
