﻿//-----本文件是对于maincall.h中部分函数的实现部分-----
#include "maincall.h"
#include "sg_ui.h"
maincall* u;
void maincall::closeEvent(QCloseEvent *event){ exit(0);}
void maincall::StartGame()//入口函数
{
    u = this;
    UI::UI_Main();
}

void maincall::_Exit()
{
    exit(0);
    //ClearScene();
}


