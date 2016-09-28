#include "sg_ui.h"
#include "maincall.h"
#include <thread>
using namespace UI;
using namespace std;
extern maincall* u;
bool check = false; //循环背景跳出标记
Item *Mainbutton[5];

void UI::UI_Main()
{
    //背景图片
    QString p[5] = {"_1.png","_2.jpg","_3.png","_4.png","_5.jpg"};
    QString f[5] = {"1.png","2.png","3.png","4.png","5.png"};
    Item* bg = u->AddPixmapItem(BG+"M_BG.png",0,0);
    u->SetItemLayer(bg,2);
    Item* grid = u->AddPixmapItem(BG+"M_Grid.png",0,0);
    u->SetItemLayer(grid,5);
    u->SetOpacityItem(grid,0);
    u->AnimationSetOpacityItem(grid,1,300);
    Item* bar = u->AddPixmapItem(BG+"M_Informationbar.png",1570,0);
    u->SetItemLayer(bar,4);
    u->AnimationMoveItem(bar,0,0,200);

    //按钮
    u->AddExpansionSlot("UI_Start",UI_Start); //绑定非主三类函数
    Mainbutton[0] = u->AddButtonItem(BU+"M_NewGame_U.png",-380,100,"UI_Start",BU+"M_NewGame_D.png");
    Mainbutton[1] = u->AddButtonItem(BU+"M_CGame_U.png",-380,187,"",BU+"M_CGame_D.png");
    Mainbutton[2] = u->AddButtonItem(BU+"M_About_U.png",-380,274,"",BU+"M_About_D.png");
    Mainbutton[3] = u->AddButtonItem(BU+"M_Set_U.png",-380,361,"",BU+"M_Set_D.png");
    Mainbutton[4] = u->AddButtonItem(BU+"M_Exit_U.png",-380,448,"_Exit",BU+"M_Exit_D.png");
    //按钮的特效
        u->SetItemLayer(Mainbutton[0],6);
        u->SetItemLayer(Mainbutton[1],6);
        u->SetItemLayer(Mainbutton[2],6);
        u->SetItemLayer(Mainbutton[3],6);
        u->SetItemLayer(Mainbutton[4],6);
        u->AnimationMoveItem(Mainbutton[0],45,100,100);
        u->AnimationMoveItem(Mainbutton[1],45,187,150);
        u->AnimationMoveItem(Mainbutton[2],45,274,200);
        u->AnimationMoveItem(Mainbutton[3],45,361,250);
        u->AnimationMoveItem(Mainbutton[4],45,448,300);
    while(1){
        //背景循环
        for(int i = 0;i<5;i++)
        {
            Item* p1 = u->AddPixmapItem(LO+p[i],0,0);
            Item* f1 = u->AddPixmapItem(LO+f[i],400,-100);
            SynchronousStart(yb1)
            u->SetItemLayer(p1,1);
            u->SetItemLayer(f1,3);
            u->SetOpacityItem(p1,0);
            u->SetOpacityItem(f1,0);
            u->AnimationSetOpacityItem(p1,1,500,"yb1");
            u->AnimationSetOpacityItem(f1,1,1000,"yb1");
            u->AnimationMoveItem(f1,200,-100,1000,"yb1");
            SynchronousFinish()
            if(check == true)goto outwhile;//如果循环标记改变 跳出循环


            SynchronousStart(yb2)
            u->AnimationSetOpacityItem(p1,0,300,"yb2");
            u->AnimationSetOpacityItem(f1,0,300,"yb2");
            SynchronousFinish()
            u->MoveItem(f1,400,-100);
            u->RemoveItem(p1);
            u->RemoveItem(f1);
            if(check == true)goto outwhile;
        }
    }
    outwhile:;
}

void UI::UI_Start()
{
        u->SetItemLayer(Mainbutton[0],6);
        u->SetItemLayer(Mainbutton[1],6);
        u->SetItemLayer(Mainbutton[2],6);
        u->SetItemLayer(Mainbutton[3],6);
        u->SetItemLayer(Mainbutton[4],6);
        u->AnimationMoveItem(Mainbutton[4],-380,448,300);
        u->AnimationMoveItem(Mainbutton[3],-380,361,250);
        u->AnimationMoveItem(Mainbutton[2],-380,274,200);
        u->AnimationMoveItem(Mainbutton[1],-380,187,150);
        u->AnimationMoveItem(Mainbutton[0],-380,100,100);

    for(int i = 0; i <=3; i++)
        u->RemoveItem(Mainbutton[i]);

    //绘制开始选择界面
    u->AddExpansionSlot("UI_Return",UI_Return); //绑定非主三类函数
    u->AddExpansionSlot("UI_MainStory",UI_MainStory);
    Mainbutton[0] = u->AddButtonItem(BU+"M_MainStory_U.png",-380,100,slotname,BU+"M_MainStory_D.png");
    Mainbutton[1] = u->AddButtonItem(BU+"M_SecondStory_U.png",-380,187,"",BU+"SecondStory_D.png");
    Mainbutton[2] = u->AddButtonItem(BU+"M_EditMode_U.png",-380,274,"",BU+"M_EditMode_D.png");
    Mainbutton[3] = u->AddButtonItem(BU+"M_MyGirl_U.png",-380,361,"",BU+"M_MyGirl_D.png");
    Mainbutton[4] = u->AddButtonItem(BU+"M_Return_U.png",-380,448,"UI_Return",BU+"M_Return_D.png");
    //按钮的特效
        u->SetItemLayer(Mainbutton[0],6);
        u->SetItemLayer(Mainbutton[1],6);
        u->SetItemLayer(Mainbutton[2],6);
        u->SetItemLayer(Mainbutton[3],6);
        u->SetItemLayer(Mainbutton[4],6);
        u->AnimationMoveItem(Mainbutton[0],45,100,100);
        u->AnimationMoveItem(Mainbutton[1],45,187,150);
        u->AnimationMoveItem(Mainbutton[2],45,274,200);
        u->AnimationMoveItem(Mainbutton[3],45,361,250);
        u->AnimationMoveItem(Mainbutton[4],45,448,300);
}

void UI::UI_Return()
{
        u->SetItemLayer(Mainbutton[0],6);
        u->SetItemLayer(Mainbutton[1],6);
        u->SetItemLayer(Mainbutton[2],6);
        u->SetItemLayer(Mainbutton[3],6);
        u->SetItemLayer(Mainbutton[4],6);
        u->AnimationMoveItem(Mainbutton[0],-380,100,100);
        u->AnimationMoveItem(Mainbutton[1],-380,187,150);
        u->AnimationMoveItem(Mainbutton[2],-380,274,200);
        u->AnimationMoveItem(Mainbutton[3],-380,361,250);
        u->AnimationMoveItem(Mainbutton[4],-380,448,300);

    //删除开始选择界面按钮
        for(int i = 0; i <=4; i++)
            u->RemoveItem(Mainbutton[i]);


    Mainbutton[0] = u->AddButtonItem(BU+"M_NewGame_U.png",-380,100,"",BU+"M_NewGame_D.png");
    Mainbutton[1] = u->AddButtonItem(BU+"M_CGame_U.png",-380,187,"",BU+"M_CGame_D.png");
    Mainbutton[2] = u->AddButtonItem(BU+"M_About_U.png",-380,274,"",BU+"M_About_D.png");
    Mainbutton[3] = u->AddButtonItem(BU+"M_Set_U.png",-380,361,"",BU+"M_Set_D.png");
    Mainbutton[4] = u->AddButtonItem(BU+"M_Exit_U.png",-380,448,"_Exit",BU+"M_Exit_D.png");
    //按钮的特效
        u->SetItemLayer(Mainbutton[0],6);
        u->SetItemLayer(Mainbutton[1],6);
        u->SetItemLayer(Mainbutton[2],6);
        u->SetItemLayer(Mainbutton[3],6);
        u->SetItemLayer(Mainbutton[4],6);
        u->AnimationMoveItem(Mainbutton[0],45,100,100);
        u->AnimationMoveItem(Mainbutton[1],45,187,150);
        u->AnimationMoveItem(Mainbutton[2],45,274,200);
        u->AnimationMoveItem(Mainbutton[3],45,361,250);
        u->AnimationMoveItem(Mainbutton[4],45,448,300);
        //u->AddMusic();
}

Item* UI::UI_AddFigure(Item* name, QString findname)
{
    //u->RemoveItem(name);
    name = u->AddPixmapItem(":/Data/Image/Figuer/"+findname+".png",0,-100);
    u->SetOpacityItem(name,0);
    u->AnimationSetOpacityItem(name,1,100);
    return name;
}

Item* UI::UI_SetGameBackGround(Item* name, QString findname)
{
    name = u->AddPixmapItem(":/Data/Image/Background/"+findname+".png",0,0);
    u->SetOpacityItem(name,0);
    u->AnimationSetOpacityItem(name,1,50);
    return name;
}

Item* UI::UI_SetGameText(QString name, int wordsize, int R, int B, int G)
{
    ifstream text(name);
    string word;
    string w;
    while(getline(text,w))
        word += w + "\n";   //添加换行符

    QString _word; = QString::fromStdString(word);
    QString jiequ;= _word.section(fenge,Tsum,Tsum);
}

void UI::UI_MainStory()
{
    check = true;
    Item* textbar =  u->AddPixmapItem(BG+"文字框.png",0,500);
    u->SetItemLayer(textbar,7);
    u->SetOpacityItem(textbar,0);
    u->AnimationSetOpacityItem(textbar,1,200);


    QString Bup[6] = {"返回_上.png",//设置每个按钮图片
                      "存档_上.png",
                      "读档_上.png",
                      "快进_上.png",
                      "放大_上.png",
                      "设置_上.png"};

    QString MainFun[6] ={   "UI_StoryReturn",
                            "",
                            "",
                            "",
                            "",
                            ""};

    QString Bdo[6] ={
            "返回_下.png",
            "存档_下.png",
            "读档_下.png",
            "快进_下.png",
            "放大_下.png",
            "设置_下.png",
    };

    int Tbx = 752;
    Item* But[6];
    for(int i = 0; i < 6; i++)      //循环输出按钮
    {
        But[i] = u->AddButtonItem(BU+Bdo[i],Tbx,480,MainFun[i],BU+Bup[i],"",100);
        u->SetOpacityItem(But[i],0.0);
        u->AnimationSetOpacityItem(But[i],1,80);
        u->SetItemLayer(But[i],8);
        Tbx = Tbx+35;               //每次循环自动增加X坐标
    }
    u->AddExpansionSlot("UI_StoryReturn",UI_StoryReturn);
}

void UI::UI_StoryReturn()
{
    u->ClearScene();
    check = false;
    //UI_Start();
}

void UI::UI_FightFigure(QString *SGnames, QString *DSnames)
{
    //
}

void UI::UI_FightFigure(QString *SGname, QString *DSname)
{
    //
}
