#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

//#include <cstdint>

using namespace std;

class IFStage
{
private:
    int PC;
    string instruction;
    bool execute;

public:
    IFStage();
    ~IFStage();
    void setInstrction(string input) { instruction = input; };
    string GetInstrction() { return instruction; }
};
