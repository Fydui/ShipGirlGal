﻿#include "sg_function.h"

extern int Sum;
extern int _Sum;
extern int Tbx;
SG_Function* sgfu;
//extern ParametersStru *Cle_1 = new ParametersStru; //退出函数全局指针

SG_Function::SG_Function(library* fu)
{
    fn = fu;
}

void SG_Function::SG_Return()
{


    for(int i =Sum;_Sum >= i; _Sum--)
    {
        fn->DeleteItem(fn->AllItem[_Sum]);
    }
    //_Sum = _Sum -Sum;

    Tbx = 752;
}
