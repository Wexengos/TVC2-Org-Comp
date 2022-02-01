#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "R_instructions.h"

R_instructions::R_instructions()
{
}
// EXStage::~EXStage();

string R_instructions::r_type(int function)
{
    switch (function)
    {
    case 32:
        // add(res, a0, a1);
        return "add";
        break;
    case 43:
        // sub(res, a0, a1);
        break;
    case 34:
        return "sub";
        // sub(res, a0, a1);
        break;
    case 37:
        // Or(res, a0, a1);
        return "or";
        break;
    case 42:
        // slt(res, a0, a1);
        return "slt";
        break;
    case 8:
        // jr(res, a0, a1);
        return "jr";
        break;
    default:
        break;
    }
}

// void R_instructions::add(Word *res, Word *a0, Word *a1)
// {
//     res->i = a0->i + a1->i;
// }

// void R_instructions::sub(Word *res, Word *a0, Word *a1) { res->i = a0->i - a1->i; };
// void R_instructions::And(Word *res, Word *a0, Word *a1) { res->i = a0->i & a1->i; }; // Se for letra minuscula da zika > and é paralavra reservada
// void R_instructions::Or(Word *res, Word *a0, Word *a1)
// {
//     res->i = a0->i & a1->i;
// }; // Se for letra minuscula da zika > or é paralavra reservada
// void R_instructions::slt(Word *res, Word *a0, Word *a1)
// {

//     if (a0->i < a0->i)
//     {
//         res->i = 1;
//     }
//     else
//     {
//         res->i = 0;
//     }
// };

// void R_instructions::jr(Word *res, Word *a0, Word *a1){

// };
