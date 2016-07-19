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
        //样式一
        /*
        sl->AddPixmapItem(SG+"main_light_bg.png",0,0);

        SynchronousStart(ff)
        Item* m = sl->AddPixmapItem(ST+"中间.png",0,341);
        sl->SetOpacityItem(m,0.0);
        sl->AnimationSetOpacityItem(m,1,50,"ff");


        Item* mp = sl->AddPixmapItem(ST+"中间上.png",0,343);
        sl->AnimationMoveItem(mp,0,320,50);
        SynchronousFinish()
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
    */


        //样式二
        sl->AddPixmapItem(SG+"办公室.png",0,0);
        Item*fn = sl->AddTextItem("Loading...","微软雅黑",28,255,255,255,465,327);

        sl->AddPixmapItem(ST+"科幻背景.png",0,0);


        Item*mr = sl->AddPixmapItem(ST+"中心圆.png",421,241);
        sl->SetOpacityItem(mr,0.0);
        sl->AnimationSetOpacityItem(mr,1,150);

        SynchronousStart(ff)
        Item*mr2 = sl->AddPixmapItem(ST+"半圆.png",-156,202);
        sl->AnimationMoveItem(mr2,0,202,80,"ff");
        SynchronousFinish()

        Item* t1 = sl->AddButtonItem(ST+"长按钮_上.png",-239,231,"",ST+"长按钮_下.png");
        sl->AnimationMoveItem(t1,43,231,50);
        Item* t2 = sl->AddButtonItem(ST+"中按钮_上.png",-240,324,"",ST+"中按钮_下.png");
        sl->AnimationMoveItem(t2,120,324,45);
        Item* t3 = sl->AddButtonItem(ST+"短按钮_上.png",-200,415,"",ST+"短按钮_下.png");
        sl->AnimationMoveItem(t3,60,415,40);
        Item* cb = sl->AddPixmapItem(ST+"大侧边栏.png",615,0);
        sl->SetOpacityItem(cb,0.0);
        sl->AnimationSetOpacityItem(cb,1,100);

        Item* xcb = sl->AddPixmapItem(ST,"信息栏.png",720,76);
        sl->SetOpacityItem(xcb,0.0);
        sl->AnimationSetOpacityItem(scb,1,100);

        sl->AnimationSetOpacityItem(fn,0.0,50);
        sl->AnimationSetOpacityItem(mr,0.0,50);




}

void SG_StartGame::SG_StartUIDeleteItem(Item*l)
{
    sl->DeleteItem(l);
}
