#include <iostream>
#include <string>
//#include <cstdint>
#include "Simulator.h"

using namespace std;

struct BinaryInst
{
public:
    byte b[16];
};

Simulator::Simulator()
{
    PC = 0;
    registers = new Registers *[32];
    memory = new Memory *[32];

    IFStage *IF = new IFStage();
    IDStage *ID = new IDStage();
    EXStage *EX = new EXStage();
    WBStage *WB = new WBStage();
}

void Simulator::setRegisters()
{
    string tempRegisters[] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6",
                              "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$s8", "$ra"};

    for (int i = 0; i < 32; i++)
    {
        Registers *temp = new Registers();
        temp->setName(tempRegisters[i]);
        temp->setValue(i);

        this->setReg(i, temp);

        // cout << "entrou no " << i << this->getReg(i)->getName() << endl;
        // reg[i]->setName(tempRegisters[i]);
    }
}

void Simulator::IFStageExec(string input)
{
    // cout << reinterpret_cast<BinaryInst*>(32+1) << " REINTERPRETOU" << endl;
    if (this->isIDStage || this->PC_left)
    {
        isIFStage = true;

        return;
    }

    cout << "INPUT IF Stage exec" << input << endl;

    cout << "SIZE OF INPUT " << sizeof(input) << " bytes";

    this->IF->setInstruction(input);
    this->IF->setThisInstAddr(this->PC);
    this->IF->setNextInstAddr(this->PC + sizeof(input));

    this->PC_left = true;
    this->IF->setExecuted(false);
    this->isIFStage = false;
}

void Simulator::IDStageExec()
{
    if (this->IF->getExecuted())
    {
        cout << "cagou aq no " << this->IF->getExecuted() << endl;
        return;
    }

    if (this->isEXStage)
        this->isIDStage = true;
    {
        cout << "cagou acolá" << endl;
        return;
    }

    cout << "Instrução maneira: " << this->IF->getInstruction() << endl;

    InfoInst auxInfoInst;
    auxInfoInst.setType(this->ID->binToType(this->IF->getInstruction()));
    auxInfoInst.setConstant(Word((int)0));
    auxInfoInst.setOffset(Word((int)0));
    auxInfoInst.setAddress(Word((int)0));

    cout << "O tipo é " << auxInfoInst.getType() << endl;

    // else if (_instInfo.instType == _jal || _instInfo.instType == _jalr) {
    //     _instInfo.rd = 31;
    //     _instInfo.rde = true;
    //     ++(registerStatus[31]);
    // }
}

void Simulator::exec(string input)
{
    setRegisters();

    this->IFStageExec(input);
    this->IDStageExec();

    // {
    //     for (int i = 0; i < 32; i++)
    //         cout << "O registrador é o " << registers[i]->getName() << endl;
    // }
}
