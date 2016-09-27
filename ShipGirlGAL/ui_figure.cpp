#include "ui_figure.h"
QSqlQuery* sql;
ui_figure::ui_figure()
{
    db = QSqlDatabase::addDatabase("QSQLITE"); //添加数据库驱动链接sqlite
}

QString ui_figure::OpenSQl(QString SQLname)
{
    db.setDatabaseName(SQLname);
    if(!db.open()) return "Error";

    sql = new QSqlQuery;                      //初始化数据库操作指针
    return "Done";
}

QString ui_figure::FindFigureData(QString figurename, QString figuredata)
{
    this->OpenSQl("SG.db");
    QString id ;
    QString read;
    QString ming = "SELECT * FROM SG WHERE NAME LIKE '"+ figurename +"%'";
    QString mingg = "SELECT * FROM DS WHERE NAME LIKE '"+ figurename +"%'";
    QString ling = "SELECT SG."+figuredata+" FROM SG WHERE ID ="+id;
    QString lingg = "SELECT "+figuredata+" FROM DS WHERE ID ="+id;
    //检查名字是否在我方(SG)
    sql->exec(ming);
    while(sql->next())  id = sql->value(0).toString();  //通过名字查找对应的ID
    sql->exec(ling);
    while(sql->next())  read = sql->value(0).toString();//知道了名字和id之后 就可以找到figuredata(特定的参数)

    if(read != "") return read;                         //如果re不是空 则证明名字在数据库的SG表中 代表着我方(玩家一方)
    else if(read == "")                                 //检查re是否在DS表中 代表着敌方电脑一方 (如果re是空的 则证明要么所查找的名字不在SG中 要么名字写错了)
    {
        sql->exec(mingg);
        while(sql->next())  id = sql->value(0).toString();
        sql->exec(lingg);
        while(sql->next())  read = sql->value(0).toString();
        return read;
    }
    else                                                //如果既不在SG表又不在DS表中 返回错误
    {
        //错误界面
        read = "Error";
        return read;
    }
}

QString ui_figure::FindFigureTeam(QString figurename)
{
    QString id ;
    QString ming = "SELECT * FROM SG WHERE NAME LIKE '"+ figurename +"%'";
    QString mingg = "SELECT * FROM DS WHERE NAME LIKE '"+ figurename +"%'";
    sql->exec(ming);                      //接着看名字在不在SG中
    while(sql->next())    id = sql->value(0).toString();

    if(id == "")                            //如果不在SG中 则查看是否在DS中
    {
        sql->exec(mingg);
        while(sql->next())    id = sql->value(0).toString();

        if(id != "") return "DS";           //如果在DS中
        else "没有找到该人物,请核对数据库以及人物名字是否正确";
        //报错界面
    }
    else   return "SG";                                 //如果在SG中
}
