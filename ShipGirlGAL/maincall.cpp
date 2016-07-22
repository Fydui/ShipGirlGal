//-----本文件是对于maincall.h中部分函数的实现部分-----
#include "sg_ui.h"
#include "maincall.h"
//maincall* mainc;
//extern SG_UI* sgui;
extern int _Sum;
void maincall::StartGame()//入口函数
{
    //AddButtonItem("E:/Code/cpp/ShipGirlGAL/SG/Background/按钮背景2上.png",170,170,"test");
    //AddPixmapItem("E:/Code/cpp/ShipGirlGAL/SG/Background/按钮背景2上.png",170,170,"test");
    //connect();
    su->SG_MainUI();

}

void maincall::_StartMainUi()
{
    su->SG_StartUI();
}

void maincall::_StartText()
{
    //_Return();
    su->SG_StartTextUi();
    start->SG_StartText();
}

void maincall::_ReturnUi()
{
    su->SG_UiReturn();
    _Return();
}

void maincall::_Return()

{
    su->SG_UiReturn();
    fun->SG_Return();
    //_Sum = 27;
}

void maincall::_Exit()
{
    exit(0);
}
