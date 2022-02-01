#include <iostream>
#include <string>
//#include <cstdint>
#include "Simulator.h"
#include "R_instructions.h"
#include "J_instructions.h"
#include "I_instructions.h"
using namespace std;

Simulator::Simulator()
{
    PC = 0;
    registers = new Registers *[32];

    IF = NULL;
    ID = NULL;
    EX = NULL;
    MEM = NULL;
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
    cout << "Setando registradores" << endl;
    string tempRegisters[] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6",
                              "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$s8", "$ra"};

    for (int i = 0; i < 32; i++)
    {
        // cout << i;
        Registers *temp = new Registers();
        temp->setName(tempRegisters[i]);

        this->setReg(i, temp);

        // cout << "entrou no " << i << this->getReg(i)->getName() << endl;
        //  reg[i]->setName(tempRegisters[i]);
    }
    // cout << "Fim";
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
    // if (IF->getExecuted())
    // {
    //     return;
    // }

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

    this->PC_left = true;
    aux->setExecuted(true);
    this->isIFStage = false;
    IF = aux;
    cout << "Finalizando  IFStage." << endl;
}

void Simulator::IDStageExec()
{
    cout << endl
         << "Executando IDStage." << endl;
    // if (this->IF->getExecuted())
    // {
    //     return;
    // }

    // if (this->isEXStage)
    // {
    //     this->isIDStage = true;
    //     //
    //    }

    cout << "IDStage >> " << IF->getInstruction();
    IDStage *aux;
    InfoInst auxInfoInst;

    char str = aux->binToType(IF->getInstruction());

    cout << "Saiu bin to type= " << str << endl;
    if (aux->getOpcode() == 0)
    {
        R_instructions *r_instru = new R_instructions();
        auxInfoInst.setAddress(aux->getRd());
        auxInfoInst.setTypeI(0);
        string decodeInst = r_instru->r_type(aux->getFunction());
        auxInfoInst.setAluOp(01);
        if (decodeInst == "add")
        {
            cout << "ADD" << endl;
            auxInfoInst.setInstruction("add");
        }
        if (decodeInst == "sub")
        {
            cout << "SUB" << endl;
            auxInfoInst.setInstruction("sub");
        }
        if (decodeInst == "and")
        {
            cout << "AND" << endl;
            auxInfoInst.setInstruction("and");
        }
        if (decodeInst == "or")
        {
            cout << "OR" << endl;
            auxInfoInst.setInstruction("or");
        }
        if (decodeInst == "sl")
        {
            cout << "SL" << endl;
            auxInfoInst.setInstruction("sl");
        }
    }
    else if (aux->getOpcode() != 0)
    {
        cout << "Tipo I" << endl;
        I_instructions *i_instru = new I_instructions();
        auxInfoInst.setTypeI(1);
        string decodeInst = i_instru->i_type(aux->getOpcode());

        if (decodeInst == "lw")
        {
            cout << "LW" << endl;
            auxInfoInst.setInstruction("lw");
            auxInfoInst.setAddress(aux->getRt());
            auxInfoInst.setAluOp(01);
            auxInfoInst.setMemRead(true);
            auxInfoInst.setMemWrite(false);
            auxInfoInst.setRegWrite(true);
        }
        if (decodeInst == "sw")
        {
            cout << "SW" << endl;
            auxInfoInst.setInstruction("sw");
            auxInfoInst.setAddress(aux->getRt());
            auxInfoInst.setAluOp(01);
            auxInfoInst.setMemRead(false);
            auxInfoInst.setMemWrite(true);
            auxInfoInst.setRegWrite(false);
        }
        if (decodeInst == "beq")
        {
            auxInfoInst.setInstruction("beq");
            cout << "BEQ" << endl;
            auxInfoInst.setAddress(aux->getRt());
            auxInfoInst.setAluOp(01);
            auxInfoInst.setMemRead(false);
            auxInfoInst.setMemWrite(true);
            auxInfoInst.setRegWrite(false);
        }
        if (decodeInst == "bne")
        {
            auxInfoInst.setInstruction("bne");
            cout << "BNE" << endl;
            auxInfoInst.setAddress(aux->getRt());
            auxInfoInst.setAluOp(01);
            auxInfoInst.setMemRead(false);
            auxInfoInst.setMemWrite(false);
            auxInfoInst.setRegWrite(false);
        }
        if (decodeInst == "addi")
        {
            auxInfoInst.setInstruction("addi");
            cout << "ADDI" << endl;
            auxInfoInst.setAddress(aux->getRt());
            auxInfoInst.setAluOp(00);
            auxInfoInst.setMemRead(false);
            auxInfoInst.setMemWrite(true);
            auxInfoInst.setRegWrite(true);
        }
    }
    else if (aux->getFunction() == 0 || aux->getOpcode() == 0)
    {
        cout << "Tipo J" << aux->getOpcode() << endl;
        J_instructions *j_instru = new J_instructions();
        auxInfoInst.setTypeI(0);

        string decodeInst = j_instru->j_type(aux->getOpcode());

        if (decodeInst == "j")
        {
            cout << "J" << endl;
            auxInfoInst.setInstruction("j");
            auxInfoInst.setAddress(aux->getRt());
            auxInfoInst.setMemRead(false);
            auxInfoInst.setMemWrite(false);
            auxInfoInst.setRegWrite(false);
        }

        if (decodeInst == "jr")
        {
            cout << "JR" << endl;
            auxInfoInst.setInstruction("jr");
            auxInfoInst.setMemRead(false);
            auxInfoInst.setMemWrite(false);
            auxInfoInst.setRegWrite(false);
        }
    }
    aux->setInfo(auxInfoInst);
    ID = aux;

    cout
        << "Opcode da instrucao >> " << aux->getOpcode() << endl;

    cout << "Finalizando IDStage." << endl;
}

void Simulator::EXStageExec()
{
    // cout << endl
    //      << "Executando EXStage." << endl;

    // InfoInst auxInfoInst = ID->getInfo();
    // EXStage *aux = new EXStage();
    // string str = auxInfoInst.getInstruction();

    // if (str)
    // {
    //     auxInfoInst.setRs;
    // }
}

void Simulator::MEMStage()
{
}

void Simulator::WBStage()
{

    if (WB->getInfo().getRegWrite())
    {
        this->setRegValue(WB->getInfo().getAddress().to_ulong(), WB->getResult());
    }
}

void Simulator::exec(string input)
{

    setRegisters();
    cout << "Aqui";
    this->IFStageExec(input);
    this->IDStageExec();
    //  this->EXStageExec();

    // printRegisters();

    // {
    //     for (int i = 0; i < 32; i++)
    //         cout << "O registrador é o " << registers[i]->getName() << endl;
    // }
}
