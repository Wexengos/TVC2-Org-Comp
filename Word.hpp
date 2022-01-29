#ifndef WORD_HPP
#define WORD_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
typedef unsigned char byte;

union Word
{
    int i;
    unsigned int ui;
    struct
    {
        byte b0, b1, b2, b3;
    };

    Word() { i = 0; }
    Word(int _i) : i(_i) {}
    Word(unsigned int _ui) : ui(_ui) {}
    Word(byte _b0, byte _b1, byte _b2, byte _b3) : b0(_b0), b1(_b1), b2(_b2), b3(_b3) {}
};

#endif