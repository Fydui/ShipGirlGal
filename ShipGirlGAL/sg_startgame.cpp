#include "sg_startgame.h"
#include "sg_ui.h"
SG_StartGame* ss;
//extern SG_UI* sgui;

SG_StartGame::SG_StartGame(library* s)
{
    sl = s;

}

void SG_StartGame::SG_StartUI()

{
    ss = this;
    sl->AddPixmapItem(SG+"main_light_bg.png",0,0);

    Item*up = sl->AddPixmapItem("E:/Code/cpp/ShipGirlGAL/SG/Background/strat_item_p.png",-1080,0);
    sl->AnimationMoveItem(up,0,0,100);

    Item*dow = sl->AddPixmapItem("E:/Code/cpp/ShipGirlGAL/SG/Background/start_item_d.png",1080,400);
    sl->AnimationMoveItem(dow,-250,400,100);
}
