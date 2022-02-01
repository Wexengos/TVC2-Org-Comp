#include <iostream>
#include <string>
//#include <cstdint>
#include "Simulator.h"
#include "R_instructions.h"
#include "J_instructions.h"

using namespace std;

Simulator::Simulator()
{
    PC = 0;
    registers = new Registers *[32];
    memory = new Memory *[32];

    IF = NULL;
    ID = NULL;
    EX = NULL;
    WB = NULL;

    PC_left = false;
    isIFStage = false;
    isIDStage = false;
    isEXStage = false;
    isMEMStage = false;
    isWBStage = false;
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

void Simulator::printRegisters()
{
    cout << "Banco de registradores: " << endl;
    for (int i = 0; i < 32; i++)
    {
        cout << i + 1 << " - Registrador -> " << this->getReg(i)->getName() << endl;
    }
}

void Simulator::IFStageExec(string input)
{

    cout << endl
         << "Excutando IFStage." << endl;

    if (this->isIDStage || this->PC_left)
    {
        isIFStage = true;
        cout << "Fechando IFStage." << endl;
        return;
    }

    IFStage *aux = new IFStage();

    aux->setInstruction(input);
    aux->setThisInstAddr(this->PC);
    aux->setNextInstAddr(this->PC + sizeof(input));

    this->PC_left = true;
    aux->setExecuted(false);
    this->isIFStage = false;
    IF = aux;
    cout << "Finalizando  IFStage." << endl;
}

void Simulator::IDStageExec()
{
    cout << endl
         << "Executando IDStage." << endl;
    if (this->IF->getExecuted())
    {
        return;
    }

    if (this->isEXStage)
    {
        this->isIDStage = true;
        //
    }

    cout << "IDStage >> " << IF->getInstruction();

    InfoInst auxInfoInst;

    IDStage *aux = new IDStage();

    auxInfoInst.setType(aux->binToType(IF->getInstruction()));
    auxInfoInst.setConstant(Word((int)0));
    auxInfoInst.setOffset(Word((int)0));
    auxInfoInst.setAddress(Word((int)0));
    aux->setInfo(auxInfoInst);
    ID = aux;

    cout << "Opcode da instrucao >> " << ID->getOpcode() << endl;
    cout << "O tipo da instrucao >> " << auxInfoInst.getType() << endl;

    // else if (_instInfo.instType == _jal || _instInfo.instType == _jalr) {
    //     _instInfo.rd = 31;
    //     _instInfo.rde = true;
    //     ++(registerStatus[31]);
    // }

    cout << "Finalizando IDStage." << endl;
}

void Simulator::EXStageExec()
{
    cout << endl
         << "Executando EXStage." << endl;

    InfoInst auxInfoInst = ID->getInfo();
    EXStage *aux = new EXStage();
    Word a0, a1, res, res0;

    cout << "OpCode: " << ID->getOpcode() << " " << ID->getFunction() << endl;
    char str = auxInfoInst.getType()[0];

    switch (str)
    {
    case 'R':
    {
        R_instructions *rtype = new R_instructions();
        rtype->r_type(&res, &a0, &a1, ID->getFunction());
        break;
    }
    case 'J':
    {
        J_instructions *jtype = new J_instructions();
        jtype->j_type(&res, auxInfoInst.getAddress(), ID->getFunction());
        break;
    }
    case 'I':
    {
        cout << "Pending: I Type" << endl;
        return;
        break;
    }
    default:
        break;
    }

    cout << "Los Registras: res: " << res.i << ", a0: " << a0.i << ", a1: " << a1.i << endl;
}

void Simulator::exec(string input)
{

    setRegisters();
    this->IFStageExec(input);
    this->IDStageExec();
    this->EXStageExec();

    // printRegisters();

    // {
    //     for (int i = 0; i < 32; i++)
    //         cout << "O registrador é o " << registers[i]->getName() << endl;
    // }
}
