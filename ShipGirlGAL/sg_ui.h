#pragma once
#ifndef SG_UI_H
#define SG_UI_H
#include "library.h"
#include "sg_figure.h"

namespace SG_UI /*游戏的各种UI绘制都在此类((。﹏。*)整个一面向过程) 不可以 这不面向对象*/

{
    void UI_MainUI();                             //主界面UI
    void UI_StartUI();                            //开始游戏UI
    void UI_StartUiReturn();                      //开始游戏UI的返回
    void UI_StartTextUi();                        //游戏的界面
    void UI_UiReturn();                           //返回时通用动画
    void UI_OTextUi(QString Qoword);              //开始游戏之后输出文字的ui方法
    void UI_StartFight();                         //开始战斗的动画
    QString UI_FigureShow(QString Path, QString Name, QString Ta,float X, float Y, float X_, float Y_);
    void UI_FigureWeapons(ParametersStru Name, int switchh = 1);
    //显示人物名片并且返回人物所在表 通过FU_FigureShow自动调用(当然手动也可)

    void UI_FigureZoom(ParametersStru name);
    void UI_AnimationFigure(QString SGname, QString DSname,int SH);
    void FU_ClearTextui(Item *);                  //清除文字图层的实现(其实可以合并到返回)
    void FU_Return(int ZSum, int SSum);

    const QString ST = ":/SG/startgame/";
    const QString BG = ":/SG/Background/";                  //背景图片的路径
    const QString BT = ":/SG/Button/";                      //按钮图片的路径
    const QString FO = ":/SG/Figure/ordinary/";             //人物图片的路径
    const int BtX = 400;                                    //按钮的横坐标
    const int FontX = BtX +60;                              //字体的横坐标
    const int FontSize = 20;                                //显示字号
    const int Tby= 480;                                     //TextUi界面的按钮纵坐标

}

#endif // SG_UI_H
