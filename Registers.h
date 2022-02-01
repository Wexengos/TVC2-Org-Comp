#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

class Registers
{
private:
    bitset<32> value;
    string name;

public:
    Registers()
    {
        value = 0;
        name = "";
    };
    ~Registers(){};

    bitset<32> getValue() { return value; };
    string getName() { return name; };

    void setValue(bitset<32> val) { value = val; };
    void setName(string nam)
    {
        name = nam;
    };
};

#endif