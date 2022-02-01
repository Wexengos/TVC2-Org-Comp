#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include "InfoInst.h"
//#include <cstdint>

using namespace std;

class IDStage
{
private:
    InfoInst info;
    int opcode, function, rt, rs, rd;
    char type;
    bool executed;

public:
    IDStage();
    ~IDStage();

    char binToType(string input);
    void process(string input);
    void binaryToDecimal(string input, string auxFunct, string auxRs, string auxRd, string auxRt);

    bool getExecuted() { return executed; };
    void setExecuted(bool val) { executed = val; };

    int getOpcode() { return opcode; };
    void setOpcode(int val) { opcode = val; };

    int getFunction() { return function; };
    int getRs() { return rs; };
    int getRd() { return rd; };
    int getRt() { return rt; };

    void setInfo(InfoInst inf) { info = inf; };
    InfoInst getInfo() { return info; }
};
