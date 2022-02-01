#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class WBStage
{
private:
    InfoInst info;
    bitset<32> result;
    bitset<5> rs;
    bitset<5> rt;
    bitset<5> address;
    bool regWrite, executed;

public:
    WBStage(){};
    ~WBStage(){};
    bool getExecuted() { return executed; };
    void setExecuted(bool val) { executed = val; };

    void setInfo(InfoInst inf) { info = inf; };
    InfoInst getInfo() { return info; }

    void setResult(bitset<32> val) { result = val; };
    bitset<32> getResult() { return result; }
};