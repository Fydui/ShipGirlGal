//-----本文件是对于maincall.h中部分函数的实现部分-----
#include "sg_ui.h"
#include "maincall.h"
#include <vector>


QString SG_;
QString DS_;
QString SName;
QString DName;
ParametersStru N;
maincall* ma;
extern Item* fi;
extern Item* re;
extern Figure* sgfu;
using namespace  std;
using namespace SG_UI;
using namespace SG_StartGame;

/*这里是个"转发平台",按钮,图元等各种事件通过此类跳转到其他类和函数*/

void maincall::StartGame()//入口函数
{   ma = this;
    //sgfu->PixToAscii("E:/Code/cpp/ShipGirlGAL/SG/","太太.png");
    SG_UI::UI_MainUI();
    //fun->OpenSql("SG.db");
    //fun->FightAtt("列克星敦","战列M级");
}

void maincall::test()
{
    AddTextItem("233333333","微软雅黑",20,0,0,0,0,0);
}

void maincall::_StartMainUi()
{
    SG_UI::UI_StartUI();
}

void maincall::_StartText()
{
    SG_UI::UI_StartTextUi();
    //SG_StartGame::SG_StartText();
   // SG_UI::UI_StartFight();
}

void maincall::_ClearTextUi()
{
    SG_UI::FU_ClearTextui(re);
    fun->ReadText("M_1_1.txt","#");
}
void maincall::_Zoom(ParametersStru name)
{
    N = name;
    SG_UI::UI_FigureZoom(name);

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

void maincall::_Att(ParametersStru WeaponType)
{
    fun->FightAtt(SName,DName,WeaponType);
}
void maincall::_ReturnUi(ParametersStru re)
{
    SG_UI::UI_UiReturn();
    _Return(re);
}

void maincall::_Return(ParametersStru re)

{
    SG_UI::UI_UiReturn();
    SG_UI::FU_Return(re.intVar[0],re.intVar[1]);
    //_Sum = 27;
}

void maincall::_Exit()
{
    exit(0);
}
