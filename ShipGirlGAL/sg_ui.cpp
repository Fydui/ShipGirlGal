#include "sg_ui.h"
#include "maincall.h"
#include <thread>
using namespace UI;
using namespace std;
extern maincall* u;
bool check = false; //循环背景跳出标记
Item* bu[5];

void UI::UI_Main()
{
    const QString LO = ":/Data/Image/Loop/";

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
    bu[0] = u->AddButtonItem(BU+"M_NewGame_U.png",-380,100,"UI_Start",BU+"M_NewGame_D.png");
    bu[1] = u->AddButtonItem(BU+"M_CGame_U.png",-380,187,"",BU+"M_CGame_D.png");
    bu[2] = u->AddButtonItem(BU+"M_About_U.png",-380,274,"",BU+"M_About_D.png");
    bu[3] = u->AddButtonItem(BU+"M_Set_U.png",-380,361,"",BU+"M_Set_D.png");
    bu[4] = u->AddButtonItem(BU+"M_Exit_U.png",-380,448,"_Exit",BU+"M_Exit_D.png");
    //按钮的特效
    SynchronousStart(yb3)
        u->SetItemLayer(bu[0],6);
        u->SetItemLayer(bu[1],6);
        u->SetItemLayer(bu[2],6);
        u->SetItemLayer(bu[3],6);
        u->SetItemLayer(bu[4],6);
        u->AnimationMoveItem(bu[0],45,100,100,"yb3");
        u->AnimationMoveItem(bu[1],45,187,150,"yb3");
        u->AnimationMoveItem(bu[2],45,274,200,"yb3");
        u->AnimationMoveItem(bu[3],45,361,250,"yb3");
        u->AnimationMoveItem(bu[4],45,448,300,"yb3");
    SynchronousFinish()
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
            if(check == true)goto outwhile; //如果循环标记改变 跳出循环
            u->AnimationSetOpacityItem(p1,1,500,"yb1");
            u->AnimationSetOpacityItem(f1,1,1000,"yb1");
            u->AnimationMoveItem(f1,200,-100,1000,"yb1");
            if(check == true)goto outwhile;
            SynchronousFinish()

            SynchronousStart(yb2)
            u->AnimationSetOpacityItem(p1,0,300,"yb2");
            u->AnimationSetOpacityItem(f1,0,300,"yb2");
            if(check == true)goto outwhile;
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
    //SynchronousStart(yb3)
        u->SetItemLayer(bu[0],6);
        u->SetItemLayer(bu[1],6);
        u->SetItemLayer(bu[2],6);
        u->SetItemLayer(bu[3],6);
        u->SetItemLayer(bu[4],6);
        u->AnimationMoveItem(bu[4],-380,448,300);
        u->AnimationMoveItem(bu[3],-380,361,250);
        u->AnimationMoveItem(bu[2],-380,274,200);
        u->AnimationMoveItem(bu[1],-380,187,150);
        u->AnimationMoveItem(bu[0],-380,100,100);
    //SynchronousFinish()

    for(int i = 0; i <5; i++)
        u->RemoveItem(bu[i]);

    //绘制开始选择界面
    u->AddExpansionSlot("UI_Return",UI_Return); //绑定非主三类函数
    u->AddExpansionSlot("UI_MainStory",UI_MainStory);
    bu[0] = u->AddButtonItem(BU+"M_MainStory_U.png",-380,100,"UI_MainStory",BU+"M_MainStory_D.png");
    bu[1] = u->AddButtonItem(BU+"M_SecondStory_U.png",-380,187,"",BU+"SecondStory_D.png");
    bu[2] = u->AddButtonItem(BU+"M_EditMode_U.png",-380,274,"",BU+"M_EditMode_D.png");
    bu[3] = u->AddButtonItem(BU+"M_MyGirl_U.png",-380,361,"",BU+"M_MyGirl_D.png");
    bu[4] = u->AddButtonItem(BU+"M_Return_U.png",-380,448,"UI_Return",BU+"M_Return_D.png");
    //按钮的特效

    //SynchronousStart(yb3)
        u->SetItemLayer(bu[0],6);
        u->SetItemLayer(bu[1],6);
        u->SetItemLayer(bu[2],6);
        u->SetItemLayer(bu[3],6);
        u->SetItemLayer(bu[4],6);
        u->AnimationMoveItem(bu[0],45,100,100);
        u->AnimationMoveItem(bu[1],45,187,150);
        u->AnimationMoveItem(bu[2],45,274,200);
        u->AnimationMoveItem(bu[3],45,361,250);
        u->AnimationMoveItem(bu[4],45,448,300);
    //SynchronousFinish()
}

void UI::UI_Return()
{
    //SynchronousStart(yb3)
        u->SetItemLayer(bu[0],6);
        u->SetItemLayer(bu[1],6);
        u->SetItemLayer(bu[2],6);
        u->SetItemLayer(bu[3],6);
        u->SetItemLayer(bu[4],6);
        u->AnimationMoveItem(bu[0],-380,100,100);
        u->AnimationMoveItem(bu[1],-380,187,150);
        u->AnimationMoveItem(bu[2],-380,274,200);
        u->AnimationMoveItem(bu[3],-380,361,250);
        u->AnimationMoveItem(bu[4],-380,448,300);

    //SynchronousFinish()

    //删除开始选择界面按钮
        u->RemoveItem(bu[0]);
        u->RemoveItem(bu[1]);
        u->RemoveItem(bu[2]);
        u->RemoveItem(bu[3]);
        u->RemoveItem(bu[4]);

    u->AddExpansionSlot("UI_Start",UI_Start); //绑定非主三类函数
    bu[0] = u->AddButtonItem(BU+"M_NewGame_U.png",-380,100,"UI_Start",BU+"M_NewGame_D.png");
    bu[1] = u->AddButtonItem(BU+"M_CGame_U.png",-380,187,"",BU+"M_CGame_D.png");
    bu[2] = u->AddButtonItem(BU+"M_About_U.png",-380,274,"",BU+"M_About_D.png");
    bu[3] = u->AddButtonItem(BU+"M_Set_U.png",-380,361,"",BU+"M_Set_D.png");
    bu[4] = u->AddButtonItem(BU+"M_Exit_U.png",-380,448,"_Exit",BU+"M_Exit_D.png");
    //按钮的特效
    //SynchronousStart(yb3)
        u->SetItemLayer(bu[0],6);
        u->SetItemLayer(bu[1],6);
        u->SetItemLayer(bu[2],6);
        u->SetItemLayer(bu[3],6);
        u->SetItemLayer(bu[4],6);
        u->AnimationMoveItem(bu[0],45,100,100);
        u->AnimationMoveItem(bu[1],45,187,150);
        u->AnimationMoveItem(bu[2],45,274,200);
        u->AnimationMoveItem(bu[3],45,361,250);
        u->AnimationMoveItem(bu[4],45,448,300);
    //SynchronousFinish()
}

Item* UI::UI_MainFigure(Item* name, QString findname)
{
    //u->RemoveItem(name);
    name = u->AddPixmapItem(":/Data/Image/Figuer/"+findname+".png",0,-100);
    u->SetOpacityItem(name,0);
    u->AnimationSetOpacityItem(name,1,100);
    return name;
}

Item* UI::UI_MainBackGround(Item* name, QString findname)
{
    name = u->AddPixmapItem(":/Data/Image/Background/"+findname+".png",0,0);
    u->SetOpacityItem(name,0);
    u->AnimationSetOpacityItem(name,1,50);
    return name;
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
    UI::UI_Main();
}
