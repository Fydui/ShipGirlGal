﻿#include "sg_startgame.h"
#include "sg_figure.h"

extern Figure* sgfu;
using namespace std;
void SG_StartGame::SG_StartText()
{
    //sgfu = this;
    //sl->AddMouseEvent();
    Figure RW;
    RW.ReadText("M_1_1.txt","#");
    sgfu->OpenSql("SG.db");
    sgfu->FigureShow("列克星敦");
    sgfu->FigureShow("昆西");
    sgfu->FigureShow("罗德尼");
    sgfu->FigureShow("航母Ο级");
    sgfu->FigureShow("战列Μ级");
    sgfu->FigureShow("轻巡Ε级");

}
