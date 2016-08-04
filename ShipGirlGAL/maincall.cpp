//-----本文件是对于maincall.h中部分函数的实现部分-----
#include "sg_ui.h"
#include "maincall.h"
#include <vector>
//maincall* mainc;
//extern SG_UI* sgui;
extern int _Sum;
extern SG_StartGame* ss;
using namespace  std;

void maincall::StartGame()//入口函数
{
    //AddPixmapItem("E:/Code/cpp/ShipGirlGAL/SG/Background/木头海岸.png",0,0);
    //AddButtonItem("E:/Code/cpp/ShipGirlGAL/SG/Background/按钮背景2上.png",10,20,"","E:/Code/cpp/ShipGirlGAL/SG/Background/按钮背景2下.png");

    su->UI_MainUI();
    //ss->SG_StartText();
    //AddMouseEvent(1,510,1079,710,"_ClearTextUi");
}

void maincall::_StartMainUi()
{
    su->UI_StartUI();
    //
}

void maincall::_StartText()
{
    //_Return();
    su->UI_StartTextUi();
    start->SG_StartText();
    su->UI_StartFight();
}

void maincall::_ClearTextUi()
{
    fun->FU_ClearTextui();
    fun->FU_ReadText("M_1_1.txt","#");
}

void maincall::_ReturnUi()
{
    su->UI_UiReturn();
    _Return();
}

void maincall::_Return()

{
    su->UI_UiReturn();
    fun->FU_Return();
    //_Sum = 27;
}

void maincall::_Exit()
{
    exit(0);
}
