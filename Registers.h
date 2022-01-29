#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include "Word.hpp"
using namespace std;

class Registers
{
private:
    Word value;
    string name;

public:
    Registers()
    {
        value = 0;
        name = "";
    };
    ~Registers(){};

    Word getValue() { return value; };
    string getName() { return name; };

    void setValue(Word val) { value = val; };
    void setName(string nam)
    {
        name = nam;
    };
};