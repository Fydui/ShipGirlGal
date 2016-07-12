#pragma once
#ifndef SG_UI_H
#define SG_UI_H
#include "library.h"


class SG_UI
{
public:
    SG_UI(library*m)
    {
        ma = m;
    }
    void SG_MainUI();
private:
    library* ma;

};

#endif // SG_UI_H
