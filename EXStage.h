#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class EXStage
{
private:
    bool executed;
public:
    EXStage();
    ~EXStage();
    bool getExecuted() { return executed; };
    void setExecuted(bool val) { executed = val; };
};
