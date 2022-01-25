#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Memory
{
private:
    int32_t value;
    string name;

public:
    Memory();
    ~Memory();

    int32_t getValue() { return value; };
    string getName() { return name; };

    void setValue(int32_t val) { value = val; };
    void setName(string nam) { name = nam; };
};