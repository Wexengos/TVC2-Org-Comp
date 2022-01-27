#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


EXStage::EXStage() 
{
    execute = 0;
    is_i_type = 0;
    rd_m = 0;
    wrt_m = 0;
    alu_op = 0; 
    wrt_en = 0;
}
EXStage::~EXStage();


