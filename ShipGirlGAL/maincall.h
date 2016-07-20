//-----本文件是游戏中的一些函数调用的实现，引擎的三层封装-----

#pragma once
#include "library.h"
#include "js.h"
#include "sg_ui.h"
#include "sg_startgame.h"
#include "sg_function.h"

class maincall : public library
{
Q_OBJECT
public:
    JS_FUNCTION//关于JS操作
    SG_UI* su = new SG_UI(this);
    SG_StartGame* start = new SG_StartGame(this);
    SG_Function* fun = new SG_Function(this);

    //入口函数
    void StartGame();
    void _Return();

    //在此继续添加
private:

public slots:
    //此处容纳事件处理与线程函数
    void _StartMainUi();
    void _StartText();
    void _ReturnUi();


};

