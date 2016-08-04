#include "sg_startgame.h"
#include "sg_ui.h"
#include "sg_function.h"

SG_StartGame* ss;
extern SG_Function* sgfu;
extern SG_UI* sgui;
using namespace std;
SG_StartGame::SG_StartGame(library* s)
{
    sl = s;
}


void SG_StartGame::SG_StartText()
{
    //sgfu = this;
    //sl->AddMouseEvent();
    sgfu->FU_ReadText("M_1_1.txt","#");
    sgfu->FU_OpenSql("SG.db");
    sgfu->FU_FigureShow("列克星敦");
    sgfu->FU_FigureShow("昆西");
    sgfu->FU_FigureShow("海伦娜");

    int i = 0;

}
