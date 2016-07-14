//-----本文件是对于maincall.h中部分函数的实现部分-----
#include "sg_ui.h"
#include "maincall.h"
//maincall* mainc;
//extern SG_UI* sgui;

void maincall::StartGame()//入口函数
{
    //AddButtonItem("E:/Code/cpp/ShipGirlGAL/SG/Background/按钮背景2上.png",170,170,"test");
    //AddPixmapItem("E:/Code/cpp/ShipGirlGAL/SG/Background/按钮背景2上.png",170,170,"test");
    su->SG_MainUI();
}

void maincall::SG_StartMainUi()
{
    start->SG_StartUI();
}

