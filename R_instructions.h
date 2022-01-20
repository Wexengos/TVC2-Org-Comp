#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
// add, sub, and, or, slt

class R_instructions
{
private:
    // Array de Registradores
    string registers[32]; // Mudar esse array de string para tipo Registrador
    int registerValues[32];
    string Instructions[5];

public:
    void add();
    void sub();
    void And(); // Se for letra minuscula da zika > and é paralavra reservada
    void Or();  // Se for letra minuscula da zika > or é paralavra reservada
    void slt();
};