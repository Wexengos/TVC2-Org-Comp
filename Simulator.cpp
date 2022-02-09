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
    cycle = 0;

    registers = new Registers *[32];

    IF = new IFStage();
    ID = new IDStage();
    EX = new EXStage();
    MEM = new MEMStage();
    WB = new WBStage();

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

    cout << endl
         << "Excutando IFStage." << endl;

    IFStage *aux = new IFStage();

    aux->setInstruction(input);
    aux->setExecuted(false);

    this->IF = aux;

    cout << "A não. " << this->IF->getExecuted() << endl;

    this->PC_left = true;
    this->isIFStage = true;

    this->ID->setExecuted(true);

    cout << "Finalizando  IFStage." << endl;
}

void Simulator::IDStageExec()
{
    cout << endl
         << "Executando IDStage." << endl;

    IDStage *aux;
    InfoInst auxInfoInst;

    char str = aux->binToType(IF->getInstruction());

    if (aux->getOpcode() == 0)
    {
        R_instructions *r_instru = new R_instructions();
        auxInfoInst.setAddress(aux->getRd());
        auxInfoInst.setTypeI(0);
        string decodeInst = r_instru->r_type(aux->getFunction());
        auxInfoInst.setAluOp(1);
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
            auxInfoInst.setAluOp(1);
            auxInfoInst.setMemRead(true);
            auxInfoInst.setMemWrite(false);
            auxInfoInst.setRegWrite(true);
        }
        if (decodeInst == "sw")
        {
            cout << "SW" << endl;
            auxInfoInst.setInstruction("sw");
            auxInfoInst.setAddress(aux->getRt());
            auxInfoInst.setAluOp(1);
            auxInfoInst.setMemRead(false);
            auxInfoInst.setMemWrite(true);
            auxInfoInst.setRegWrite(false);
        }
        if (decodeInst == "beq")
        {
            auxInfoInst.setInstruction("beq");
            cout << "BEQ" << endl;
            auxInfoInst.setAddress(aux->getRt());
            auxInfoInst.setAluOp(1);
            auxInfoInst.setMemRead(false);
            auxInfoInst.setMemWrite(true);
            auxInfoInst.setRegWrite(false);
        }
        if (decodeInst == "bne")
        {
            auxInfoInst.setInstruction("bne");
            cout << "BNE" << endl;
            auxInfoInst.setAddress(aux->getRt());
            auxInfoInst.setAluOp(1);
            auxInfoInst.setMemRead(false);
            auxInfoInst.setMemWrite(false);
            auxInfoInst.setRegWrite(false);
        }
        if (decodeInst == "addi")
        {
            auxInfoInst.setInstruction("addi");
            cout << "ADDI" << endl;
            auxInfoInst.setAddress(aux->getRt());
            auxInfoInst.setAluOp(0);
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

    EX->setExecuted(true);

    aux->setInfo(auxInfoInst);

    ID = aux;

    ID->setExecuted(false);

    cout << "Finalizando IDStage." << endl;
}

void Simulator::EXStageExec()
{
    cout << endl
         << "Executando EXStage." << endl;

    EX->setExecuted(false);
    MEM->setExecuted(true);
}

void Simulator::MEMStageExec()
{
    cout << endl
         << "Executando MEMStage." << endl;

    MEM->setExecuted(false);
    WB->setExecuted(true);
}

void Simulator::WBStageExec()
{
    cout << endl
         << "Executando WBStage." << endl;

    if (WB->getInfo().getRegWrite())
    {
        this->setRegValue(WB->getInfo().getAddress().to_ulong(), WB->getResult());
    }

    WB->setExecuted(false);
}

void Simulator::exec(string input)
{
    setRegisters();

    while (true)
    {
        cout << "CICLO ATUAL: " << this->cycle << endl;
        // cout << "EXECUÇÕES: " << this->IF->getExecuted() <<
        if (this->IF->getExecuted() == 0 &&
            this->ID->getExecuted() == 0 &&
            this->EX->getExecuted() == 0 &&
            this->MEM->getExecuted() == 0 &&
            this->WB->getExecuted() == 0)
        {
            cout << "bolota" << endl;
            return;
        }

        if (this->WB->getExecuted() == 1)
        {
            this->WBStageExec();
        }

        if (this->MEM->getExecuted() == 1)
        {
            this->MEMStageExec();
        }

        if (this->EX->getExecuted() == 1)
        {
            this->EXStageExec();
        }

        if (this->ID->getExecuted() == 1)
        {
            this->IDStageExec();
        }

        if (this->IF->getExecuted() == 1)
        {
            this->IFStageExec(input);
        }

        this->cycle++;
    }

    return;

    //  this->EXStageExec();

    // printRegisters();

    // {
    //     for (int i = 0; i < 32; i++)
    //         cout << "O registrador é o " << registers[i]->getName() << endl;
    // }
}
