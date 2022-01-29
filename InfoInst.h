#ifndef INFOINST_H
#define INFOINST_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

//#include <cstdint>
#include "Word.hpp"

using namespace std;

class InfoInst
{
private:
    string type;
    byte rd;
    Word rsv, rtv, $a0, $a1;
    Word constant, offset, address;
    bool rse, rte, rde; // Controla se o registrador foi executado;
public:
    InfoInst()
    {
        rd = byte(255);
        rse = rte = rde = false;
    };
    ~InfoInst(){};
    string getType() { return type; };
    void setType(string val) { type = val; };
    Word getConstant() { return constant; };
    void setConstant(Word val) { constant = val; };
    Word getOffset() { return offset; };
    void setOffset(Word val) { offset = val; };
    Word getAddress() { return address; };
    void setAddress(Word val) { address = val; };
};

#endif