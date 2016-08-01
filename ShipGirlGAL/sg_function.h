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

using namespace std;
class SG_Function
{
public:
    SG_Function(library *fu);
    void FU_Return();        //返回功能的实现
    void FU_ClearTextui();   //清除文字图层的实现(其实可以合并到返回)
    void FU_ReadText(string name, QString fenge); //打开并读取文本,fenge是分隔符(要在文本里添加)
    void FU_Stext(int sum);                       //设置要分几次输出文本 sum要和分隔符数目相等
    void FU_OpenSql(const QString SqlName);       //喜闻乐见,打开数据库
    QString *FU_ReadSql(QString TableName, QString FindName);      //查找数据库 数据库名字 表名 数据名
    //void FU_ReadSql(QString* (Name[]) );          //查找数据库的重载

private:
    library* fn;
    SG_Function* ui;
};

#endif // SG_FUNCTION_H
