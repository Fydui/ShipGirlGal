#pragma once
#ifndef SG_UI_H
#define SG_UI_H
#include "library.h"
#include "sg_startgame.h"
class SG_UI
{

public:
    SG_UI(library*m);
    void UI_MainUI();               //主界面UI
    void UI_StartUI();              //开始游戏UI
    void UI_StartUiReturn();        //开始游戏UI的返回
    void UI_StartTextUi();          //游戏的界面
    void UI_UiReturn();             //返回时通用动画
    void UI_OTextUi(QString Qoword);              //开始游戏之后输出文字的ui方法
    void UI_StartFight();                         //开始战斗的动画
    void UI_FigureShow(QString Name, float X, float Y);

private:
    library* ma;                       //指向library的指针在构造的时候将library的this赋值 然后就能在SG_UI里调miancall的方法了,,,,,,,,,
    const QString ST = ":/SG/startgame/";
    const QString BG = ":/SG/Background/";                  //背景图片的路径
    const QString BT = ":/SG/Button/";
    const int BtX = 400;                                    //按钮的横坐标
    const int FontX = BtX +60;                              //字体的横坐标
    const int FontSize = 20;                                //显示字号


};

#endif // SG_UI_H
