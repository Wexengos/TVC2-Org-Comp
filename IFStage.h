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
    bool executed;
    

public:
    IFStage();
    ~IFStage();
    void setInstruction(string input) { instruction = input; };
    string getInstruction() { return instruction; };
    void setNextInstAddr(int value) { nextInstAddr = value; };
    int getNextInstAddr() { return nextInstAddr; };
    void setThisInstAddr(int value) { thisInstAddr = value; };
    int getThisInstAddr() { return thisInstAddr; };
    bool getExecuted() { return executed; };
    void setExecuted(bool val) { executed = val; };
};
