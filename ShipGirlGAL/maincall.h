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
    //SG_UI* su = new SG_UI(this);
    Function* fun = new Function(this);

    //入口函数
    void StartGame();


    //在此继续添加
private:

public slots:
    //此处容纳事件处理与线程函数
    void _StartMainUi();    //开始界面Ui
    void _StartText();      //开始游戏
    void _ReturnUi(ParametersStru re);       //返回动画
    void _Return(ParametersStru re);         //返回
    void _Exit();           //退出
    void _ClearTextUi();    //清除文字图层
    void _Zoom(ParametersStru name);           //缩放人物名片
    void _Att();
    void test();


};

