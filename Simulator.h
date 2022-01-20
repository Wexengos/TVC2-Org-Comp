#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Simulator
{
private:
    // Array de Registradores
    string registers[32]; // Mudar esse arruy de string para tipo Registrador
    int registerValues[32];
    string Instructions[5];

public:
    Simulator();
    void simulator_exect();
}