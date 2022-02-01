#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "InfoInst.h"
//#include <cstdint>

using namespace std;

class IDStage
{
private:
    InfoInst info;
    int opcode, function;
    string type;
    bool executed;

public:
    IDStage();
    ~IDStage();

    string binToType(string input);
    void process(string input);
    void binaryToDecimal(string input, string funct);

    bool getExecuted() { return executed; };
    void setExecuted(bool val) { executed = val; };

        int getOpcode() { return opcode; };
    void setOpcode(int val) { opcode = val; };

    int getFunction() { return function; };
    void setFunction(int val) { function = val; };

    void setInfo(InfoInst inf) { info = inf; };
    InfoInst getInfo() { return info; }
};
