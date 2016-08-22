﻿#include "sg_ui.h"
#include "maincall.h"
#include "GlobalVar.h"
extern maincall* ma;

Item* But[6];
Item* sg = new Item[6];//我方人物数组
Item* ds = new Item[6];//敌方人物数组
Item* lh;              //左边的 黑幕
Item* rh;              //右边黑幕
Item* dc;              //下大文字框
Item* fi;              //人物
Item* re;
Item* we1;
Item* we2;
Item* we3;
Item* t1;
Item* t2;
Item* t3;

int Yz = 0;            //敌方名片纵坐标(用于放大之后缩回)
int Tbx = 752;         //TextUi界面的按钮横坐标
int aaa = 0;           //我方名片序号 用于判断
int bbb = 0;           //敌方
int G = 0;
int ssum = 0;          //我方名片计数变量 最终于我方名片数目相同 用于循环
int dsum = 0;          //敌方
int GG = 0;
int K = 0;
ParametersStru ggs;

using namespace SG_UI;

void SG_UI::UI_MainUI()
{
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
}

void SG_UI::UI_StartUI() //绘制开始菜单界面
{
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
    ParametersStru res;
    res.intVar<<23<<11;

    ma->AddPixmapItem(BG+"办公室.png",0,0);
    Item*fn = ma->AddTextItem("Loading...","微软雅黑",28,255,255,255,465,327);
    ma->AddPixmapItem(BG+"科幻背景.png",0,0);
    Item*mr = ma->AddPixmapItem(BG+"中心圆.png",421,241);

    SynchronousStart(ff)
    ma->SetOpacityItem(mr,0.0);
    ma->AnimationSetOpacityItem(mr,1,50,"ff");
    Item* na = ma->AddPixmapItem(ST+"上名称栏.png",453,-45);
    ma->AnimationMoveItem(na,453,0,30,"ff");
    SynchronousFinish()

    SynchronousStart(dd)
    Item*mr2 = ma->AddPixmapItem(BG+"半圆.png",-156,202);
    Item* cb = ma->AddPixmapItem(BG+"大侧边栏.png",615,0);
    ma->AnimationMoveItem(mr2,0,202,40,"dd");
    ma->SetOpacityItem(cb,0.0);
    ma->AnimationSetOpacityItem(cb,1,100,"dd");
    SynchronousFinish()

    Item* xcb = ma->AddPixmapItem(BG+"信息栏.png",720,76);
    Item* t1 = ma->AddButtonItem(BT+"长按钮_上.png",-239,231,"",ST+"长按钮_下.png");
    Item* t2 = ma->AddButtonItem(BT+"中按钮_上.png",-240,324,"",ST+"中按钮_下.png");
    Item* t3 = ma->AddButtonItem(BT+"短按钮_上.png",-200,415,"_ReturnUi",ST+"短按钮_下.png","",100,res);

    SynchronousStart(cc)

    ma->AnimationMoveItem(t1,43,231,40,"cc");
    ma->AnimationMoveItem(t2,120,324,45,"cc");
    ma->AnimationMoveItem(t3,60,415,50,"cc");
    ma->SetOpacityItem(xcb,0.0);
    ma->AnimationSetOpacityItem(xcb,1,100,"cc");
    SynchronousFinish()

    Item* zx = ma->AddButtonItem(BT+"主线剧情_上.png",741,414,"_StartText",ST+"主线剧情_下.png");
    ma->SetOpacityItem(zx,0.0);
    ma->AnimationSetOpacityItem(zx,1,100);

    Item* zx2 = ma->AddButtonItem(BT+"支线剧情_上.png",741,525,"",ST+"支线剧情_下.png");
    ma->SetOpacityItem(zx2,0.0);
    ma->AnimationSetOpacityItem(zx2,1,100);

    ma->AnimationSetOpacityItem(fn,0.0,100);
    ma->AnimationSetOpacityItem(mr,0.0,100);
}

void SG_UI::UI_StartTextUi()//绘制开始游戏界面
{

    //sgui = this;
    ParametersStru ret;
    ret.ItemVar<< re;
    ret.intVar<<33<<24;
    ma->AddPixmapItem(BG+"木头海岸.png",0,0);
    SynchronousStart(mm)
    fi = ma->AddPixmapItem(FO+"列克星敦.png",-600,0);
    ma->AnimationMoveItem(fi,-300,0,50,"mm");
    SynchronousFinish()

    dc =  ma->AddPixmapItem(BG+"下大文字框.png",0,500,"_ClearTextUi",ret);
    ma->SetItemLayer(dc,10);
    ma->SetOpacityItem(dc,0.0);
    ma->AnimationSetOpacityItem(dc,1,50);

    //ma->AddMouseEvent(0,520,1080,720,"_ClearTextUi");

    //用循环来输出图元 不过感觉更麻烦了QwQ
    QString Bup[6] = {"返回_上.png",//设置每个按钮图片
                      "存档_上.png",
                      "读档_上.png",
                      "快进_上.png",
                      "放大_上.png",
                      "设置_上.png"};

    QString MainFun[6] ={"_Return",
                            "",
                            "",
                            "",
                            "",
                            ""};
    ParametersStru parabut[6];
        parabut[0].intVar<<32<<24;
        parabut[1] = _NULLParametersStru;
        parabut[2] = _NULLParametersStru;
        parabut[3] = _NULLParametersStru;
        parabut[5] = _NULLParametersStru;
        parabut[5] = _NULLParametersStru;

    QString Bdo[6];
        Bdo[0] = "返回_下.png";
        Bdo[1] = "存档_下.png";
        Bdo[2] = "读档_下.png";
        Bdo[3] = "快进_下.png";
        Bdo[4] = "放大_下.png";
        Bdo[5] = "设置_下.png";

    for(int i = 0; i < 6; i++)      //循环输出按钮
    {
        But[i] = ma->AddButtonItem(BT+Bup[i],Tbx,Tby,MainFun[i],BT+Bdo[i],"",100,parabut[i]);
        ma->SetOpacityItem(But[i],0.0);
        ma->AnimationSetOpacityItem(But[i],1,80);
        Tbx = Tbx+35;               //每次循环自动增加X坐标
    }

//    _Sum = 33;
  //  Sum = 24;
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

void SG_UI::UI_StartFight()//绘制战斗界面
{
    ParametersStru ref;
    int v = 40+ssum+dsum;
    ref.intVar<<v<<33;
    lh = ma->AddPixmapItem(BG+"左黑幕.png",-594,0);
    rh = ma->AddPixmapItem(BG+"右黑幕.png",1080,0);
    int Y = 465;

    ma->AnimationSetOpacityItem(fi,0.0,20);
    for(int i = 0;i > 6;i--)
    {
        ma->AnimationSetOpacityItem(But[i],0.0,10);
    }

    SynchronousStart(ff)
    ma->AnimationMoveItem(lh,0,0,20,"ff");
    ma->AnimationMoveItem(rh,485,0,20,"ff");
    SynchronousFinish()

    Item* fig = ma->AddPixmapItem(BG+"开始战斗.png",280,200);
    Item* re = ma->AddButtonItem(BT+"战斗返回_上.png",280,Y,"_Return",BT+"战斗返回_下.png","",100,ref);
    Item* go = ma->AddButtonItem(BT+"战斗攻击_上.png",440,Y,"",BT+"战斗攻击_下.png");
    Item* cx = ma->AddButtonItem(BT+"撤销_上.png",600,Y,"",BT+"撤销_下.png");
    Item* ad = ma->AddButtonItem(BT+"战斗托管_上.png",760,Y,"",BT+"战斗托管_下.png");
    ma->SetItemLayer(ad,2);

    SynchronousStart(mm)
    Item* butt[5] = {fig,re,go,cx,ad};
        for(int i = 0; i < 5; i++)
            ma->SetItemLayer(butt[i],8);

    ma->SetOpacityItem(fi,0);
    ma->AnimationSetOpacityItem(fig,1,10,"mm");
    ma->SetOpacityItem(re,0);
    ma->AnimationSetOpacityItem(re,1,10,"mm");
    ma->SetOpacityItem(go,0);
    ma->AnimationSetOpacityItem(go,1,10,"mm");
    ma->SetOpacityItem(cx,0);
    ma->AnimationSetOpacityItem(cx,1,10,"mm");
    ma->SetOpacityItem(ad,0);
    ma->AnimationSetOpacityItem(ad,1,10,"mm");
    SynchronousFinish()
    ma->AnimationSetOpacityItem(fig,0.0,20);
    //ma->SetItemOrder(ad,dc);
    //_Sum = 41+ssum +dsum;
    //Sum = 33;
}

QString SG_UI::UI_FigureShow(QString Path, QString Name, QString Ta, float X, float Y, float X_, float Y_)//绘制战斗人物显示
{
    if(Ta == "SG")
    {
        ParametersStru sgg;
        sgg.ItemVar<< &sg[ssum];
        sgg.intVar<< aaa << X_ << Y_;
        sgg.StringVar<<"SG"<<Ta<<Name;
        aaa++;
        sg[ssum] = *ma->AddButtonItem(Path,X,Y,"_Zoom","","",100,sgg);//Item*数组sg储存人物

        ma->SetItemLayer(&sg[ssum],3);                         //设置图片等级
        ma->AnimationMoveItem(&sg[ssum],X_,Y_,20);
        ssum++;
    }

    else
    {
        ParametersStru dss;
        dss.ItemVar<< &ds[dsum];
        dss.intVar<< bbb << Y_;
        dss.StringVar<< "DS"<<Ta<<Name;
        bbb++;
        ds[dsum] = *ma->AddButtonItem(Path,X,Y,"_Zoom","","",100,dss);          //Item*数组mp储存人物
        ma->SetItemLayer(&ds[dsum],3);                       //设置图片等级
        ma->AnimationMoveItem(&ds[dsum],X_,Y_,20);
        dsum++;
    }
    return Ta;
}

void SG_UI::UI_FigureZoom(ParametersStru name)//战斗人物显示的缩放
{


    int fsum = 0;
    Item* fgg;                  //判断传进来的是属于SG表还是DS表
    if(name.StringVar[0] == "SG")
        {
            fsum = ssum;
            fgg = new Item[6];
            fgg = sg;
            G = 1;              //如果第一点击敌方 则不放大(因为第一次点击敌方就放大看着难受
            ggs = name;
        }
    if(name.StringVar[0] == "DS" && G == 1)
        {
            fsum = dsum;
            fgg = new Item[6];
            fgg = ds;
            GG = 1;
        }

    Figure* t = new Figure;
    if(GG == 2)
    {
        if(t->ReadSql(name.StringVar[2],"CLASS") == "CV"){
            ma->RemoveItem(we1);
            ma->RemoveItem(we2);
            ma->RemoveItem(we3);
            ma->RemoveItem(t1);
            ma->RemoveItem(t2);
            ma->RemoveItem(t3);
        }
        else{
            ma->RemoveItem(we1);
            ma->RemoveItem(we2);
            ma->RemoveItem(we3);
            ma->RemoveItem(t1);
            ma->RemoveItem(t2);
            ma->RemoveItem(t3);
        }
        SG_UI::UI_FigureWeapons(ggs,1);
    }

    if(G == 1)
    {
        float zo = 0.0;
        for(int i = 0; i < fsum; i++)       //判断放大图元
        {
            zo = ma->GetItemScale(&fgg[i]); //检查所有图元缩放值
            if(zo > 1){
                    ma->ScaleItem(&fgg[i],1.0);     //如果有图元缩放值大于1就改成1

                    if(name.StringVar[0] == "DS")
                        ma->MoveItem(&fgg[i],803,Yz);//判断是否是敌方图元 重设坐标
            }
        }

        for(int j = 0; j < ssum; j++)       //重头开始判断被点击图元
        {
            if(name.intVar[0] == j)         //如果被点击图元的标记和当前循环数相等
            {
                for(int i =0; i< ssum; i++) //把所有图元的优先级降级
                {ma->SetItemLayer(&fgg[i],3);}
                ma->SetItemLayer(&fgg[j],4);//把被点击图元优先级升级(这样可以确保被点击图元显示时总在高层)

            /*由于元火缩放图元都是以左上角为标注 但敌方名片UI需要以右上角为基准缩放*/
                if(name.StringVar[0] == "DS"){
                    ma->MoveItem(&fgg[j],757,name.intVar[1]);//所以当当前点击为敌方时 先左移出来一部分
                    Yz = name.intVar[1];                     //设置被移动图元的Y
                    if(K == 0){
                            SG_UI::UI_FigureWeapons(ggs,GG);
                        }
                    GG = 2;
                }
                    ma->ScaleItem(&fgg[j],1.2);//放大
                if(name.StringVar[0] == "SG" && K == 1)
                    SG_UI::UI_FigureWeapons(ggs,GG);

            }
        }
    }
    //return name;
}

ParametersStru* SG_UI::UI_FigureWeapons(ParametersStru Name, int switchh)
{
    if(switchh == 1)
    {
        Figure* a = new Figure;
        if(a->ReadSql(Name.StringVar[2],"CLASS") == "CV"){
            we1 = ma->AddButtonItem(BT+"武器按钮1.png",Name.intVar[1],Name.intVar[2],"","","",100,Name);
            we2 = ma->AddButtonItem(BT+"武器按钮3.png",Name.intVar[1],Name.intVar[2],"","","",100,Name);
            we3 = ma->AddButtonItem(BT+"武器按钮4.png",Name.intVar[1],Name.intVar[2],"","","",100,Name);
            ma->AnimationMoveItem(we1,0,Name.intVar[2],15);
            ma->AnimationMoveItem(we2,0,Name.intVar[2],15);
            ma->AnimationMoveItem(we3,0,Name.intVar[2],15);
            ma->SetItemLayer(we1,11);
            ma->SetItemLayer(we2,11);
            ma->SetItemLayer(we3,11);
            t1 = ma->AddTextItem("副 炮","微软雅黑",30,75,185,248,37,17);
            t2 = ma->AddTextItem("舰载攻击机","微软雅黑",20,75,185,248,190,10);
            t3 = ma->AddTextItem("舰载轰炸机","微软雅黑",20,75,185,248,155,45);
            ma->SetItemLayer(t1,12);
            ma->SetItemLayer(t2,12);
            ma->SetItemLayer(t3,12);
            GG = 2; //之后把标记改成2
            K = 1;
        }
        else
        {
            we1 = ma->AddButtonItem(BT+"武器按钮1.png",Name.intVar[1],Name.intVar[2],"","","",100,Name);
            we2 = ma->AddButtonItem(BT+"武器按钮2.png",Name.intVar[1],Name.intVar[2],"","","",100,Name);
            we3 = ma->AddTextItem("   ","微软雅黑",20,0,0,0,0,0);
            ma->AnimationMoveItem(we1,0,Name.intVar[2],15);
            ma->AnimationMoveItem(we2,0,Name.intVar[2],15);
            ma->SetItemLayer(we1,11);
            ma->SetItemLayer(we2,11);

            if(a->ReadSql(Name.StringVar[2],"CLASS") == "BB" || a->ReadSql(Name.StringVar[2],"CLASS") == "CA"
                    || a->ReadSql(Name.StringVar[2],"CLASS") == "BC")
                {
                    t1 = ma->AddTextItem("主 炮","微软雅黑",30,75,185,248,Name.intVar[1]+25,Name.intVar[2]+20);
                    t2 = ma->AddTextItem("副 炮","微软雅黑",30,75,185,248,Name.intVar[1]+200,Name.intVar[2]+20);
            }
            else if(a->ReadSql(Name.StringVar[2],"CLASS") == "DD" || a->ReadSql(Name.StringVar[2],"CLASS") == "CL")
                {
                    t1 = ma->AddTextItem("主 炮","微软雅黑",30,75,185,248,Name.intVar[1]+25,Name.intVar[2]+20);
                    t2 = ma->AddTextItem("鱼 雷","微软雅黑",30,75,185,248,Name.intVar[1]+200,Name.intVar[2]+20);
            }
            else if(a->ReadSql(Name.StringVar[2],"CLASS") == "SS")
                {
                    t1 = ma->AddTextItem("近防炮","微软雅黑",25,75,185,248,Name.intVar[1]+25,Name.intVar[2]+20);
                    t1 = ma->AddTextItem("鱼 雷","微软雅黑",30,75,185,248,Name.intVar[1]+200,Name.intVar[2]+20);
            }

            t3 = ma->AddTextItem("  ","微软雅黑",30,75,185,248,155,61);
            ma->SetItemLayer(t1,12);
            ma->SetItemLayer(t2,12);
            ma->SetItemLayer(t3,12);
            GG = 2;
            K = 1;
        }
    }

    return &Name;
}

void SG_UI::UI_AnimationFigure(QString SGname, QString DSname, int SH)
{
    QString path = FO+SGname+".png";
    QString pathh =FO+DSname+".png";


    Item* s =  ma->AddPixmapItem(path,-1024,-40);
    Item* d = ma->AddPixmapItem(pathh,1080,-40);

    SynchronousStart(ff)
    ma->SetItemLayer(s,6);
    ma->SetItemLayer(d,6);
    ma->AnimationScaleItem(s,1.0,10,"ff");
    ma->AnimationMoveItem(s,-350,-40,10,"ff");
    ma->AnimationMoveItem(d,474,-40,10,"ff");
    ma->AnimationScaleItem(d,1.0,10,"ff");
    SynchronousFinish()
    ma->SetItemLayer(lh,5);
    ma->SetItemLayer(rh,5);

    Item* pd = ma->AddPixmapItem(BG+"炮弹.png",170,450);
    ma->SetItemLayer(pd,6);
    SCFun lmb = [](int time){
        float x = 250+time;
        float y = (x*x)/2048-x/2+512;
        return SCCurrentModulus{x,y,0};
    };

    SynchronousStart(vv)
    ma->MoveItem(s,-380,-10);
    ma->AnimationMoveItem(s,-350,-40,5);
    ma->AnimationMoveItem(pd,lmb,850,"vv");
    SynchronousFinish()

    QString wor = QString::number(SH);
    Item* sh = ma->AddTextItem(wor,"Lithos Pro",70,225,255,255,900,300);

    SynchronousStart(aa)
    ma->MoveItem(d,504,-40);
    ma->AnimationMoveItem(d,444,-40,5,"aa");
    SynchronousFinish()

    SynchronousStart(bb)
    ma->AnimationMoveItem(d,474,-40,5);
    ma->AnimationSetOpacityItem(sh,0.0,500,"bb");
    ma->SetItemLayer(sh,7);
    SynchronousFinish()

    SynchronousStart(qq)
    ma->AnimationMoveItem(s,-1080,-40,5,"qq");
    ma->AnimationMoveItem(d,1080,-40,5,"qq");
    SynchronousFinish()

    ma->RemoveItem(s);
    ma->RemoveItem(d);
    ma->RemoveItem(pd);
    for(int i = 0; i<ssum; i++)
        ma->ScaleItem(&sg[i],1.0);

    for(int i = 0; i<dsum; i++)
    {
        ma->ScaleItem(&ds[i],1.0);
        float yy = ma->GetItemY(&ds[i]);
        ma->MoveItem(&ds[i],803,yy);
    }

    ma->SetItemLayer(lh,2);
    ma->SetItemLayer(rh,2);

}

void SG_UI::UI_OTextUi(QString Qoword)//文本显示样式
{
    re= ma->AddTextItem(Qoword,"微软雅黑",20,0,0,0,120,510);
    ma->SetItemLayer(re,11);
    G = 0;
}

void SG_UI::UI_UiReturn()//返回时的小特♂技
{
    Item* mr;
    Item* fo;
    Item* bg;
    SynchronousStart(vv)
    bg= ma->AddPixmapItem(BG+"关闭背景.png",0,0);
    ma->AnimationSetOpacityItem(bg,1,100,"vv");
    fo = ma->AddTextItem("Loading...","微软雅黑",28,255,255,255,465,327);
    ma->AnimationSetOpacityItem(fo,1,100,"vv");
    mr = ma->AddPixmapItem(BG+"中心圆.png",421,241);
    ma->SetOpacityItem(mr,0.0);
    ma->AnimationSetOpacityItem(mr,1,100,"vv");
    SynchronousFinish()
    ma->AnimationSetOpacityItem(mr,0.0,5);

    ma->RemoveItem(mr);
    ma->RemoveItem(fo);
    ma->RemoveItem(bg);
    Yz =0;
}

void SG_UI::FU_Return(int ZSum, int SSum)
{

    for(int i =SSum;ZSum >= i; ZSum--)
    {
        ma->RemoveItem(ma->AllItem[ZSum]); //删除所在界面所有图元 完成返回
    }
    Tbx = 752;
}

void SG_UI::FU_ClearTextui(Item* te)
{
    ma->RemoveItem(te);
}
