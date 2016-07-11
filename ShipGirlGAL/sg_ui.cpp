#include "sg_ui.h"
#include "maincall.h"
SG_UI* sgui;
extern maincall* mainc;
SG_UI::SG_UI()
{
//
}


void SG_UI::SG_MainUI()
{
    sgui = this;
    mainc->AddPixmapItem("E:/Code/cpp/ShipGirlGAL/SG/Background/主界面背景.png",0,0);
}
