#include "sg_ui.h"
#include "sg_function.h"

extern SG_Function* sgfu;
SG_UI* sgui;                                //使用全局变量进行调用maincall的方法
//extern maincall* mainc;

int Sum;                                    //上级界面图元数
int _Sum;                                   //当前总图元数.
const int Tby= 502;                                     //TextUi界面的按钮纵坐标
int Tbx = 752;                                          //TextUi界面的按钮横坐标
extern SG_StartGame* ss;
//ParametersStru *Cle_1 = new ParametersStru; //退出函数全局指针


SG_UI::SG_UI(library* m)
{
    ma = m;
}

void SG_UI::SG_MainUI()
{
    sgui = this;
    //mainc->AddPixmapItem("E:/Code/cpp/ShipGirlGAL/SG/Background/主界面背景.png",0,0);
    //绘制主界面


    ma->AddPixmapItem(BG+"主界面背景.png",0,0);

    ma->AddButtonItem(BG+"按钮背景2上.png",BtX,170,"_StartMainUi",BG+"按钮背景2下.png");
    ma->AddTextItem("新的游戏","微软雅黑",FontSize,153,108,51,FontX,175);

    ma->AddButtonItem(BG+"按钮背景2上.png",BtX,240,"",BG+"按钮背景2下.png");
    ma->AddTextItem("继续游戏","微软雅黑",FontSize,153,108,51,FontX,245);

    ma->AddButtonItem(BG+"按钮背景2上.png",BtX,310,"",BG+"按钮背景2下.png");
    ma->AddTextItem("游戏设置","微软雅黑",FontSize,153,108,51,FontX,315);

    ma->AddButtonItem(BG+"按钮背景2上.png",BtX,380,"",BG+"按钮背景2下.png");
    ma->AddTextItem("关于舰R","微软雅黑",FontSize,153,108,51,FontX,385);

    ma->AddButtonItem(BG+"按钮背景2上.png",BtX,450,"_Exit",BG+"按钮背景2下.png");
    ma->AddTextItem("退出游戏","微软雅黑",FontSize,153,108,51,FontX,455);

    Sum = 11;

}

void SG_UI::SG_StartUI()
{
    sgui = this;
    //样式一
    /*
    sl->AddPixmapItem(SG+"main_light_bg.png",0,0);

    SynchronousStart(ff)
    Item* m = sl->AddPixmapItem(ST+"中间.png",0,341);
    sl->SetOpacityItem(m,0.0);
    sl->AnimationSetOpacityItem(m,1,50,"ff");


    Item* mp = sl->AddPixmapItem(ST+"中间上.png",0,343);
    sl->AnimationMoveItem(mp,0,320,50);
    SynchronousFinish()
    Item* md = sl->AddPixmapItem(ST+"中间下.png",0,355);
    sl->AnimationMoveItem(md,0,379,50);


    Item* up = sl->AddPixmapItem(ST+"strat_item_p.png",-1080,0);
    sl->AnimationMoveItem(up,0,0,80);

    Item* dow = sl->AddPixmapItem(ST+"start_item_d.png",1080,400);
    sl->AnimationMoveItem(dow,-250,400,80);


    Item* bm = sl->AddButtonItem(ST+"主线上.png",590,105,"",ST+"主线下.png");
    sl->SetOpacityItem(bm,0.0);
    sl->AnimationSetOpacityItem(bm,1,80);

    Item* bp = sl->AddButtonItem(ST+"支线上.png",70,540,"",ST+"支线下.png");
    sl->SetOpacityItem(bp,0.0);
    sl->AnimationSetOpacityItem(bp,1,80);

    Item* re = sl->AddButtonItem(ST+"返回上.png",1080,70,"",ST+"返回下.png");
    sl->AnimationRotationItem(re,180,50);
    sl->AnimationMoveItem(re,1000,70,20);
*/


    //样式二
    ma->AddPixmapItem(BG+"办公室.png",0,0);
    Item*fn = ma->AddTextItem("Loading...","微软雅黑",28,255,255,255,465,327);
    ma->AddPixmapItem(ST+"科幻背景.png",0,0);
    Item*mr = ma->AddPixmapItem(ST+"中心圆.png",421,241);



    SynchronousStart(ff)
    ma->SetOpacityItem(mr,0.0);
    ma->AnimationSetOpacityItem(mr,1,50,"ff");
    Item* na = ma->AddPixmapItem(ST+"上名称栏.png",453,-45);
    ma->AnimationMoveItem(na,453,0,30,"ff");
    SynchronousFinish()



    SynchronousStart(dd)
    Item*mr2 = ma->AddPixmapItem(ST+"半圆.png",-156,202);
    Item* cb = ma->AddPixmapItem(ST+"大侧边栏.png",615,0);
    ma->AnimationMoveItem(mr2,0,202,40,"dd");
    ma->SetOpacityItem(cb,0.0);
    ma->AnimationSetOpacityItem(cb,1,100,"dd");
    SynchronousFinish()

    Item* xcb = ma->AddPixmapItem(ST+"信息栏.png",720,76);
    Item* t1 = ma->AddButtonItem(ST+"长按钮_上.png",-239,231,"",ST+"长按钮_下.png");
    Item* t2 = ma->AddButtonItem(ST+"中按钮_上.png",-240,324,"",ST+"中按钮_下.png");
    Item* t3 = ma->AddButtonItem(ST+"短按钮_上.png",-200,415,"_ReturnUi",ST+"短按钮_下.png");

    SynchronousStart(cc)

    ma->AnimationMoveItem(t1,43,231,40,"cc");
    ma->AnimationMoveItem(t2,120,324,45,"cc");
    ma->AnimationMoveItem(t3,60,415,50,"cc");
    ma->SetOpacityItem(xcb,0.0);
    ma->AnimationSetOpacityItem(xcb,1,100,"cc");
    SynchronousFinish()



    Item* zx = ma->AddButtonItem(ST+"主线剧情_上.png",741,414,"_StartText",ST+"主线剧情_下.png");
    ma->SetOpacityItem(zx,0.0);
    ma->AnimationSetOpacityItem(zx,1,100);

    Item* zx2 = ma->AddButtonItem(ST+"支线剧情_上.png",741,525,"",ST+"支线剧情_下.png");
    ma->SetOpacityItem(zx2,0.0);
    ma->AnimationSetOpacityItem(zx2,1,100);

    ma->AnimationSetOpacityItem(fn,0.0,100);
    ma->AnimationSetOpacityItem(mr,0.0,100);
    _Sum = 23;
}

void SG_UI::SG_StartTextUi()
{
    ma->AddMouseEvent(1,510,1079,710,"_ClearTextUi");
    sgui = this;
    ma->AddPixmapItem(BG+"木头海岸.png",0,0);
    SynchronousStart(mm)
    Item* fi = ma->AddPixmapItem(ST+"太太_正常.png",-600,0);
    ma->AnimationMoveItem(fi,0,0,100,"mm");
    SynchronousFinish()

    Item* dc = ma->AddPixmapItem(ST+"下大文字框.png",0,500);
    ma->SetOpacityItem(dc,0.0);
    ma->AnimationSetOpacityItem(dc,1,50);



   Item* But[6];
    QString Bup[6] = {"返回_上.png",
                      "存档_上.png",
                      "读档_上.png",
                      "快进_上.png",
                      "放大_上.png",
                      "设置_上.png"};

    QString MainFun[6] =
    {
        "_Return",
        "",
        "",
        "",
        "",
        ""
    };

    QString Bdo[6];
        Bdo[0] = "返回_下.png";
        Bdo[1] = "存档_下.png";
        Bdo[2] = "读档_下.png";
        Bdo[3] = "快进_下.png";
        Bdo[4] = "放大_下.png";
        Bdo[5] = "设置_下.png";

    for(int i = 0; i < 6; i++)
    {
        But[i] = ma->AddButtonItem(ST+Bup[i],Tbx,Tby,MainFun[i],ST+Bdo[i]);
        ma->SetOpacityItem(But[i],0.0);
        ma->AnimationSetOpacityItem(But[i],1,80);
        Tbx = Tbx+35;
    }

    _Sum = 33;
    Sum = 24;
/*
    Item* re = ma->AddButtonItem(ST+"返回_上.png",752,Tby,"_Return",ST+"返回_下.png");
    Item* sa = ma->AddButtonItem(ST+"存档_上.png",787,Tby,"",ST+"存档_下.png");
    Item* lo = ma->AddButtonItem(ST+"读档_上.png",822,Tby,"",ST+"读档_下.png");
    Item* qu = ma->AddButtonItem(ST+"快进_上.png",857,Tby,"",ST+"快进_下.png");
    Item* fd = ma->AddButtonItem(ST+"放大_上.png",882,Tby,"",ST+"放大_下.png");
    Item* se = ma->AddButtonItem(ST+"设置_上.png",917,Tby,"",ST+"设置_下.png");

    ma->SetOpacityItem(re,0.0);
    ma->SetOpacityItem(sa,0.0);
    ma->SetOpacityItem(lo,0.0);
    ma->SetOpacityItem(qu,0.0);
    ma->SetOpacityItem(fd,0.0);
    ma->SetOpacityItem(se,0.0);

    ma->AnimationSetOpacityItem(re,1,100);
    ma->AnimationSetOpacityItem(sa,1,100);
    ma->AnimationSetOpacityItem(lo,1,100);
    ma->AnimationSetOpacityItem(qu,1,100);
    ma->AnimationSetOpacityItem(fd,1,100);
    ma->AnimationSetOpacityItem(se,1,100);
*/

}

void SG_UI::SG_OTextUi(QString Qoword)
{
    sgui =this;
    ma->AddTextItem(Qoword,"微软雅黑",20,0,0,0,0,0);

}


void SG_UI::SG_UiReturn()
{
    sgui = this;
    SynchronousStart(vv)
    Item* bg= ma->AddPixmapItem(ST+"关闭背景.png",0,0);
    ma->AnimationSetOpacityItem(bg,1,100,"vv");
    Item* fo = ma->AddTextItem("Loading...","微软雅黑",28,255,255,255,465,327);
    ma->AnimationSetOpacityItem(fo,1,100,"vv");
    Item* mr = ma->AddPixmapItem(ST+"中心圆.png",421,241);
    ma->SetOpacityItem(mr,0.0);
    ma->AnimationSetOpacityItem(mr,1,100,"vv");
    SynchronousFinish()
    _Sum = _Sum+3;


}


