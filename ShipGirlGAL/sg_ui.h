#pragma once
#ifndef SG_UI_H
#define SG_UI_H
#include "library.h"
class SG_UI
{

public:
    SG_UI(library*m);
    void SG_MainUI();              //主界面UI
    void SG_StartUI();             //开始游戏界面UI


private:
    library* ma;                       //指向library的指针在构造的时候将library的this赋值 然后就能在SG_UI里调miancall的方法了,,,,,,,,,
    const QString BG = ":/SG/Background";                  //背景图片的路径
    const int BtX = 400;               //按钮的横坐标
    const int FontX = BtX +60;         //字体的横坐标
    const int FontSize = 20;           //显示字号

};

#endif // SG_UI_H
