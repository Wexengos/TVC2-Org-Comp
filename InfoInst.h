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
    Word rsv, rtv, $a0, $a1;
    bool rse, rte, rde; // Controla se o registrador foi executado;
public:
    InfoInst(){};
    ~InfoInst(){};
};
