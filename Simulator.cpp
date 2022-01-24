#include <iostream>
#include <string>
//#include <cstdint>

#include "Simulator.h"

using namespace std;

Simulator::Simulator()
{
    //Fetch *fetch = new Fetch();
}

void Simulator::exec(string input)
{
    fetch->process(input);
}