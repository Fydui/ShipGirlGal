#include "sg_ui.h"
#include "maincall.h"
#include <thread>
using namespace UI;
using namespace std;
extern maincall* u;
bool check = false;

void UI::chick(){
    check = true;
    u->RemoveItem(u->AllItem[3]);
    u->RemoveItem(u->AllItem[4]);
    u->RemoveItem(u->AllItem[5]);
    u->RemoveItem(u->AllItem[3]);
    u->RemoveItem(u->AllItem[3]);
}

void UI::UI_Start()
{
    const QString LO = ":/Data/Image/Loop/";

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

    u->AddExpansionSlot("_CGame",chick);
    Item* ng = u->AddButtonItem(BU+"M_NewGame_U.png",-380,100,"",BU+"M_NewGame_D.png");
    Item* cg = u->AddButtonItem(BU+"M_CGame_U.png",-380,187,"_CGame",BU+"M_CGame_D.png");
    Item* st = u->AddButtonItem(BU+"M_About_U.png",-380,274,"",BU+"M_About_D.png");
    Item* ab = u->AddButtonItem(BU+"M_Set_U.png",-380,361,"",BU+"M_Set_D.png");
    Item* ex = u->AddButtonItem(BU+"M_Exit_U.png",-380,448,"_Exit",BU+"M_Exit_D.png");
    SynchronousStart(yb3)
        u->SetItemLayer(ng,6);
        u->SetItemLayer(cg,6);
        u->SetItemLayer(st,6);
        u->SetItemLayer(ab,6);
        u->SetItemLayer(ex,6);
        u->AnimationMoveItem(ng,45,100,100,"yb3");
        u->AnimationMoveItem(cg,45,187,150,"yb3");
        u->AnimationMoveItem(st,45,274,200,"yb3");
        u->AnimationMoveItem(ab,45,361,250,"yb3");
        u->AnimationMoveItem(ex,45,448,300,"yb3");
    SynchronousFinish()
    //u->AddMusic(":/Data/Music/port-day.mp3",100,1);

    while(1){
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


