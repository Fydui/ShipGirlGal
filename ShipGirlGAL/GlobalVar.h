﻿//-----本文件作为一些全局变量的储存，它们会被描述游戏中的各种信息-----
#pragma once
#include "head.h"
#include "NewType.h"

//-引擎所使用的信号变量类
class LFEvent : public QObject
{
    Q_OBJECT
public:
    //您可以在此添加需要传递到js中的全局变量，成员前请加Q_INVOKABLE
    //例：Q_INVOKABLE int var;


signals:
    //您可以在此添加异步变同步等功能需要用到的信号，只需声明，无需实现
    //例子：void FunctionFinish();

};

//-引擎自带的全局常量
static const QString title="舰少GAL";//窗口标题
static const int WindowsWidth=1080;//窗口宽
static const int WindowsHeigh=720;//窗口高
static const int MaximumWidth=10000;//舞台最大宽
static const int MaximunHeigh=10000;//舞台最大高
//-引擎自带的全局变量
extern LFEvent *lfevent;
extern QObject *thob;
extern QGraphicsScene *MainScene;//声明舞台
extern GraphicsView *MainView;//声明视图
//-用户自行添加的全局变量
