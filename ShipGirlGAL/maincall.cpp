//-----本文件是对于maincall.h中部分函数的实现部分-----
#include "sg_ui.h"
#include "maincall.h"
//maincall* mainc;
//extern SG_UI* sgui;
extern int _Sum;
extern SG_StartGame* ss;
void maincall::StartGame()//入口函数
{

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
