#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class Register
{
private:
    bitset<5> value;
    string name;

public:
    Register()
    {
        value = 0;
        name = "";
    };
    ~Register(){};

    int32_t getValue() { return value; };
    string getName() { return name; };

    void setValue(int32_t val) { value = val; };
    void setName(string nam)
    {
        name = nam;
    };
};