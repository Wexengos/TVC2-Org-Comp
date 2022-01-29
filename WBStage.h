#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class WBStage
{
private:
    bool wrt_e;
    bool executed;

public:
    WBStage(){};
    ~WBStage(){};
    bool getExecuted() { return executed; };
    void setExecuted(bool val) { executed = val; };
};