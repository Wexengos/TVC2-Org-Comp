#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

//#include <cstdint>

using namespace std;

class IDStage
{
private:
    int opcode;
    string type;
    bool execute;

public:
    IDStage();
    ~IDStage();

    void getOpcode(string input);
    void process(string input);
    int32_t binaryToDecimal(string input);
};
