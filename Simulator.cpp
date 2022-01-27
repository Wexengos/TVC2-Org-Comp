#include <iostream>
#include <string>
//#include <cstdint>
#include "Simulator.h"

using namespace std;

Simulator::Simulator()
{
    reg = new Register *[32];
    IFStage *IF = new IFStage();
    IDStage *ID = new IDStage();
}

void Simulator::setRegisters()
{
    string tempRegisters[] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6",
                              "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$s8", "$ra"};

    for (int i = 0; i < 32; i++)
    {
        Register *temp = new Register();
        temp->setName(tempRegisters[i]);
        temp->setValue(i);

        this->setReg(i, temp);

        // cout << "entrou no " << i << this->getReg(i)->getName() << endl;
        // reg[i]->setName(tempRegisters[i]);
    }
}

void Simulator::exec(string input)
{
    cout << "Hhaahhahahaha" << endl;
    setRegisters();
    IF->setInstrction(input);
    ID->getOpcode(IF->GetInstrction());
    for (int i = 0; i < 32; i++)
    {
        cout << "O registrador é o " << reg[i]->getName() << endl;
    }
}
