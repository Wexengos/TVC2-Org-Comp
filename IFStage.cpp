#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
//#include <cstdint>
#include "IFStage.h"

IFStage::IFStage() 
{
    execute = 0;
    PC = 0;
    instruction = '';
}
IFStage::~IFStage();


