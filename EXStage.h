#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Register.h"

using namespace std;

class EXStage
{
private:


    Register *r1;
    Register *r2;
    Register *rt; //Registrador temporario
    Register *rs; // Registrador de resultado
    Register *wra;// Registrador com endereço do destino
    

    bool execute;
    bool is_i_type;// variavel de controle para instruções i
    bool rd_m; //variavel de controle para leitura de memoria
    bool wrt_m;  //variavel de controle para escrita de memoria
    bool alu_op; 
    bool wrt_en;

    
public:
    EXStage();
    ~EXStage();
};
