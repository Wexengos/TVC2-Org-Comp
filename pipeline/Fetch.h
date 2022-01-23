#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

class Fetch
{
private:
    int a;
public:
    Fetch();
    ~Fetch();

    int32_t getOpcode(string input);
    void process(string input);
    int32_t binaryToDecimal(string input);
};
