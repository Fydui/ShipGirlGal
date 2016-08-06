#include "sg_function.h"
#include "sg_ui.h"

extern int Sum;             //上级界面图元数
extern int _Sum;            //当前界面图元数
extern int Tbx;             //文本框上面按钮们的横坐标
int DoneSum = 20;           //文本判断变量 必须和分隔符数目相等
int Tsum =0;                //文本计数变量
//int tablsum = 0;
extern QSqlDatabase db;     //数据库连接变量
extern SG_UI* sgui;         //UI界面的指针
SG_Function* sgfu;          //给别的类用的
//extern QString* Table[12];  //
QSqlQuery* query;           //数据库操作指针
int SGxy = 0;               //我方人物名片的计数变量
int DSxy = 0;               //敌方人物名片的计数变量
float Sx = -277.0;          //我方人物名片的横 纵坐标
float Sy = 0.0;
float Dx = 1080.0;          //敌方人物名片的横 纵 坐标
float Dy = 0.0;
//QString (*oout)[11];
//extern ParametersStru *Cle_1 = new ParametersStru; //退出函数全局指针

SG_Function::SG_Function(library* fu)

{
    fn = fu;
}

void SG_Function::FU_ClearTextui()
{
    //int Dang = 33;
    //int Bao = 32;
    //for(int i = Bao; Dang >= i; Dang--)
        fn->DeleteItem(fn->AllItem[33]);
}

void SG_Function::FU_Return()
{

    int _Sum_ = _Sum;


    for(int i =Sum;_Sum_ >= i; _Sum_--)
    {
        fn->DeleteItem(fn->AllItem[_Sum_]); //删除所在界面所有图元 完成返回
    }

    if(_Sum == 36 && Sum == 24) //判断是否返回到选关 如果返回到选关界面则重设_Sum,Sum
    {                           //如果不重设 则无法返回到开始主界面
        _Sum = 23;
        Sum = 11;

    }

    Tbx = 752;
}


void SG_Function::FU_ReadText(string name, QString fenge)
{
    ifstream text(name);
    string word;
    string w;
    QString _word;

    while(getline(text,w))
    {
        word += w + "\n";   //添加换行符
    }
    _word = QString::fromStdString(word);

     QString jiequ;
     jiequ= _word.section(fenge,Tsum,Tsum);
     sgui->UI_OTextUi(jiequ);
     if(Tsum == DoneSum)    //如果文本输出完毕
     {
        //sgui->SG_OTextUi("#DONE#");
        //FU_ClearTextui();
        Tsum = 0;
     }
     else
     {
         Tsum++;            //如果没输出完 将文本计数变量自加
     }

/*
    ifstream infile(name);			//打开文件
    string word = "";				//全部文本
    string tmp;						//在读的当前行
    while (getline(infile, tmp)) {
        word += tmp + "\n";
    }
    word = word.substr(0, word.length() - 2); //删除最后的换行符

    vector<string>str_list;
    int comma_n = 0;
    while (1) {

        string tmp_s = "";				//"这里"是分隔符
        const char* ccfengge = fenge.c_str();
        comma_n = word.find(ccfengge); //查找分隔符第一次出现的位置
        if (comma_n == -1) {			//没找到的话

            str_list.push_back(word);  //把剩下的都塞进去
            break;
        }
        tmp_s = word.substr(0, comma_n);		    //把这一段截断
        word.erase(0, comma_n + fenge.length());	//把这一段抹去
        str_list.push_back(tmp_s);					//把截断的字符串加入容器
    }

    //int sum;
    string oword = "";
    QString Qoword = "";

    for (int i = 0; i < sum; i++) {

        oword = str_list.at(0);
        Qoword = QString::fromStdString(oword);
        sgui->SG_OTextUi(Qoword);
        //fn->AddMouseEvent(135,500,945,700,"_ClearTextUi");
    }*/
}

void SG_Function::FU_OpenSql(const QString SqlName)
{
    db.setDatabaseName(SqlName);    //设置数据库名字
    if(!db.open())                  //判断是否打开数据库
    {
        //错误界面
    }
    query = new QSqlQuery;          //初始化数据库操作变量

}

void SG_Function::FU_CloseSql()
{
    db.close();                     //关闭数据库
}

QString* SG_Function::FU_FindSql(QString TableName,QString FindName)
{
    QString ming = "SELECT * FROM " + TableName + " WHERE NAME LIKE " + "'"+ FindName +"%'"; //数据库命令
    out = new QString[11];
    query->exec(ming);
        while(query->next())
        {
            for(int i = 0; i< 11; i++)
            {
                out[i] = query->value(i).toString();
            }
        }

    return out; //返回参数数组
}

QString SG_Function::FU_ReadSql(QString *ReadStr, int Sum)  //接受参数数组
{
    data = new QString[11];
    QString Error = "错误:Sum超出范围";
    data = ReadStr;
    if(Sum < 0 || Sum > 11)                                 //判断Sum范围(这个Sum从0到11对应着人物的参数)详情请看数据库
        return Error;
    else
        return data[Sum];
}

QString SG_Function::FU_ReadSql(QString Name, QString DataName)
{
    QString id ;
    QString ming = "SELECT * FROM SG WHERE NAME LIKE '"+ Name +"%'";
    QString mingg = "SELECT * FROM DS WHERE NAME LIKE '"+ Name +"%'";

    QString re;
    query->exec(ming);
    //检查名字是否在我方(SG)
    while(query->next())
     {
         id = query->value(0).toString();       //通过名字查找对应的ID
     }
    QString ling = "SELECT SG."+DataName+" FROM SG WHERE ID ="+id;

    query->exec(ling);
    while(query->next())
       re = query->value(0).toString();         //知道了名字和id之后 就可以找到DataName(特定的参数)

    if(re != "")                                //如果re不是空 则证明名字在数据库的SG表中 代表着我方(玩家一方)
        return re;

    else if(re == "")                           //检查re是否在DS表中 代表着敌方电脑一方 (如果re是空的 则证明要么所查找的名字不在SG中 要么名字写错了)
    {
        query->exec(mingg);
        while(query->next())
        {
            id = query->value(0).toString();
        }
        QString lingg = "SELECT "+DataName+" FROM DS WHERE ID ="+id;

        query->exec(lingg);
        while(query->next())
            re = query->value(0).toString();

        return re;
    }

    else                                        //如果既不在SG表又不在DS表中 返回错误
    {
        //错误界面
        re = "Error";
        return re;
    }
}

QString SG_Function::FU_FigureShow(QString Name)
{
    QString Tab;
    //首先判断人满了没有
    QString error;
    if(SGxy == 6 || DSxy ==6)
    {
        //报错界面
        error = "人物已经达到上限,无法添加,请删除人物";
        return error;
    }

    //然后判断人物是否在数据库中
    QString id ;
    QString ming = "SELECT * FROM SG WHERE NAME LIKE '"+ Name +"%'";
    QString mingg = "SELECT * FROM DS WHERE NAME LIKE '"+ Name +"%'";
    query->exec(ming);                      //接着看名字在不在SG中

    while(query->next())
     {
         id = query->value(0).toString();
     }

    if(id == "")                            //如果不在SG中 则查看是否在DS中
    {
        query->exec(mingg);
        while(query->next())
        {
            id = query->value(0).toString();
        }
        if(id != "")                        //如果在DS中
            {
            Dy =  DSxy*Dy;                  //设置人物Y坐标
            QString _Name = ":/SG/Figure/little/" + Name+"_名片.png";
            sgui->UI_FigureShow(_Name,"DS",Dx,Dy,803,Dy);//显示人物
            DSxy++;                         //将人物计数变量+1
            Dy = 78;
            //Table[tablsum] = "DS";
        }
        else
        {
            //报错界面
            error = "没有找到该人物,请核对数据库以及人物名字是否正确";
            return error;
        }

    }
    else                                    //如果在SG中
    {
        Sy = SGxy*Sy;
        QString _Name = ":/SG/Figure/little/" + Name+"_名片.png";
        sgui->UI_FigureShow(_Name,"SG",Sx,Sy,0,Sy);
        SGxy++;
        Sy = 78;
        //Table[tablsum] = "SG";
    }

}

QString SG_Function::FU_CheckTable(QString Name)
{
    //然后判断人物是否在数据库中
    QString id ;
    QString ta;
    QString ming = "SELECT * FROM SG WHERE NAME LIKE '"+ Name +"%'";
    QString mingg = "SELECT * FROM DS WHERE NAME LIKE '"+ Name +"%'";
    query->exec(ming);                      //接着看名字在不在SG中

    while(query->next())
        id = query->value(0).toString();


    if(id == "")                            //如果不在SG中 则查看是否在DS中
    {
        query->exec(mingg);
        while(query->next())
            id = query->value(0).toString();


        if(id != "")                        //如果在DS中
        {
            ta = "DS";
            return ta;
        }

        else
        {
            //报错界面
            QString error = "没有找到该人物,请核对数据库以及人物名字是否正确";
            return error;
        }
    }

    else                                    //如果在SG中
    {
        ta = "SG";
        return ta;
    }
}
