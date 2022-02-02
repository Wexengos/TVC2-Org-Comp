#ifndef INFOINST_H
#define INFOINST_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

//#include <cstdint>

using namespace std;

class InfoInst
{
private:
    bool executed, type_i, mem_read, mem_write, reg_write;
    bitset<32> PC;
    int rs;
    int rt;
    bitset<32> reg1;
    bitset<32> reg2;
    bitset<16> Immediate;
    bitset<2> alu_op;
    bitset<5> address;
    string instruction;

public:
    InfoInst(){};
    ~InfoInst(){};

    void setAddress(bitset<5> val) { address = val; };
    bitset<5> getAddress() { return address; };

    void setAluOp(bitset<2> val) { alu_op = val; };
    bitset<2> getAluOp() { return alu_op; };

    void setImmediate(bitset<16> val) { Immediate = val; };
    bitset<16> getImmediate() { return Immediate; };

    void setReg1(bitset<32> val) { reg1 = val; };
    bitset<32> getReg1() { return reg1; };

    void setReg2(bitset<32> val) { reg2 = val; };
    bitset<32> getReg2() { return reg2; };

    void setRt(int val) { rt = val; };
    int getRt() { return rt; };

    void setRs(int val) { rs = val; };
    int getRs() { return rs; };

    void setPC(bitset<32> val) { PC = val; };
    bitset<32> getPC() { return PC; };

    void setTypeI(bool val) { type_i = val; };
    bool getTypeI() { return type_i; };

    void setMemRead(bool val) { mem_read = val; };
    bool getMemRead() { return mem_read; };

    void setMemWrite(bool val) { mem_write = val; };
    bool getMemWrite() { return mem_write; };

    void setRegWrite(bool val) { reg_write = val; };
    bool getRegWrite() { return reg_write; };

    void setInstruction(string str) { instruction = str; };
    string getInstruction() { return instruction; };
};

#endif