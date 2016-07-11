//-----本文件是对于maincall.h中部分函数的实现部分-----
#include "sg_ui.h"
#include "maincall.h"
maincall* mainc;
extern SG_UI* sgui;
void maincall::StartGame()//入口函数
{
    mainc = this;
    sgui->SG_MainUI();
}
