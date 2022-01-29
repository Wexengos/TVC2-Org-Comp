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
    int opcode;
    string type;
    bool executed;

public:
    IDStage();
    ~IDStage();

    string binToType(string input);
    void process(string input);
    void binaryToDecimal(string input);

    bool getExecuted() { return executed; };
    void setExecuted(bool val) { executed = val; };
};
