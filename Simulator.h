#ifndef Simulator_H
#define Simulator_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
//#include <cstdint>
#include "Fetch.h"

using namespace std;

class Simulator
{
private:
    Fetch *fetch;

    // Array de Registradores
    string registers[32]; // Mudar esse arruy de string para tipo Registrador
    int registerValues[32];
    string Instructions[5];

    int32_t maxTam;          //tamanho máximo do input
    int32_t numInstructions; //numero de instruções executadas
    int32_t programCount;    //linha atual de execução da simulação
    int32_t stopFlag;        //flag de parada de execução

public:
    Simulator();
    ~Simulator(){};

    void exec(string input);
};

#endif