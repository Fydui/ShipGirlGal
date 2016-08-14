#ifndef SG_FUNCTION_H
#define SG_FUNCTION_H
#include "library.h"
#include <fstream>
#include <vector>
#include <string>
#include <QtSql/QSql>
#include <qsqlquery.h>
#include <QSqlQuery>
#include <QtCore/QFile>
#include <qmainwindow.h>
#include <map>

using namespace std;

class Function   /*此游戏所有功能性函数都在这个类里(这是我这破游戏里最面向对象的一个类QAQ)*/
{
public:
    Function(library *fu);
    Function();
    ~Function();

    /*数据库相关*/

    void ReadText(string name, QString fenge); //打开并读取文本,fenge是分隔符(要在文本里添加)
    void Stext(int sum);                       //设置要分几次输出文本 sum要和分隔符数目相等
    void Return();                             //返回功能的实现
    void OpenSql(const QString SqlName);                        //喜闻乐见,打开数据库
    void CloseSql();
    QString* FindSql(QString TableName, QString FindName);      //查找数据库  表名 数据名
    QString ReadSql(QString* ReadStr,int Sum);                  //将所查找内容返回 和楼上配合使用
    QString ReadSql(QString Name, QString DataName);            //返回指定目标的指定参数
    QString CheckTable(QString Name);                           //检查一个名字在哪个表里 返回表名
    QString FigureShow(QString Name);                           //显示人物(小)
    void FightAtt(QString SG_, QString DS_);


private:
    library* fn;
    Function* ui;
    QString* out;
    QString* data;
    QString FU  = ":/SG/Figure/little/";
};

#endif // SG_FUNCTION_H
