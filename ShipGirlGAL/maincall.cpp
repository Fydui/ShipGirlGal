//-----本文件是对于maincall.h中部分函数的实现部分-----
#include "sg_ui.h"
#include "maincall.h"
#include <vector>
//maincall* mainc;
//extern SG_UI* sgui;
extern int _Sum;
extern SG_StartGame* ss;
QString SG_;
QString DS_;
QString SName;
QString DName;
ParametersStru N;

using namespace  std;

/*这里是个"转发平台",按钮,图元等各种事件通过此类跳转到其他类和函数*/
void maincall::StartGame()//入口函数
{
    //su->UI_MainUI();
    AddMouseEvent(0,510,1079,710,"test");
    AddPixmapItem("E:/Code/cpp/ShipGirlGAL/SG/Background/下大文字框.png",0,400);
    //AddPixmapItem("E:/Code/cpp/ShipGirlGAL/SG/Background/科幻背景.png",0,0);
    //AddPixmapItem("E:/Code/cpp/ShipGirlGAL/SG/Background/左黑幕.png",0,0);
//*/
}

void maincall::test()
{
    AddTextItem("233333333","微软雅黑",20,0,0,0,0,0);
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
    //su->UI_StartFight();
}

void maincall::_ClearTextUi()
{
    fun->FU_ClearTextui();
    fun->FU_ReadText("M_1_1.txt","#");
}
void maincall::_Zoom(ParametersStru name)
{
    N = name;
    su->UI_FigureZoom(name);

    QString s = N.StringVar[0];
    if(s == "SG")
    {
        SG_ = "SG";
        SName = N.StringVar[2];
    }
    if(s == "DS" && SG_ == "SG")
    {
        DName = N.StringVar[2];
    }

}

void maincall::_Att()
{
    fun->FU_FightAtt(SName,DName);
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
