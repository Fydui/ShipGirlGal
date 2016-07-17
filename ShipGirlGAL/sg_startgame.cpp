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

        //SynchronousStart(ff)
        Item* m = sl->AddPixmapItem(ST+"中间.png",0,341);
        sl->SetOpacityItem(m,0.0);
        sl->AnimationSetOpacityItem(m,1,50);
        //SynchronousFinish()

        Item* mp = sl->AddPixmapItem(ST+"中间上.png",0,343);
        sl->AnimationMoveItem(mp,0,320,50);

        Item* md = sl->AddPixmapItem(ST+"中间下.png",0,355);
        sl->AnimationMoveItem(md,0,379,50);


        Item* up = sl->AddPixmapItem(ST+"strat_item_p.png",-1080,0);
        sl->AnimationMoveItem(up,0,0,80);

        Item* dow = sl->AddPixmapItem(ST+"start_item_d.png",1080,400);
        sl->AnimationMoveItem(dow,-250,400,80);


        Item* bm = sl->AddButtonItem(ST+"主线上.png",590,105,"",ST+"主线下.png");
        sl->SetOpacityItem(bm,0.0);
        sl->AnimationSetOpacityItem(bm,1,80);

        Item* bp = sl->AddButtonItem(ST+"支线上.png",70,540,"",ST+"支线下.png");
        sl->SetOpacityItem(bp,0.0);
        sl->AnimationSetOpacityItem(bp,1,80);

        Item* re = sl->AddButtonItem(ST+"返回上.png",1080,70,"",ST+"返回下.png");
        sl->AnimationRotationItem(re,180,50);
        sl->AnimationMoveItem(re,1000,70,20);


}
