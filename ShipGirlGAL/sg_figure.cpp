#include "sg_figure.h"
#include "sg_ui.h"
#include "maincall.h"
extern int Sum;             //上级界面图元数
extern int _Sum;            //当前界面图元数
extern int Tbx;             //文本框上面按钮们的横坐标
extern maincall* ma;
int DoneSum = 21;           //文本判断变量 必须和分隔符数目相等
int Tsum =0;                //文本计数变量
extern Item* font;
//int tablsum = 0;
extern QSqlDatabase db;     //数据库连接变量
Figure* sgfu;          //给别的类用的
QString SG;
QString DS;
//extern QString* Table[12];  //
QSqlQuery* query;           //数据库操作指针
int SGxy = 0;               //我方人物名片的计数变量
int DSxy = 0;               //敌方人物名片的计数变量
int Sx = -277.0;          //我方人物名片的横 纵坐标
int Sy = 0.0;
int Dx = 1080.0;          //敌方人物名片的横 纵 坐标
int Dy = 0.0;
using namespace SG_UI;

Figure::Figure(library* fu)
{
    fn = fu;
}

Figure::Figure()
{
    ID = 0;
    CLASS = "";
    NAME = "";
    HP = 0;
    ATK = 0;
    ARMOR = 0;
    DODGE = 0;
    PLANESUM = 0;
    AA = 0;
    TORPEDO = 0;
}

Figure::~Figure()
{
    Dy = 0.0;
    Sy = 0.0;
    Sx = -277.0;
    Dx = 1080.0;
    SGxy = 0;
    DSxy = 0;
}
void Figure::ReadText(string name, QString fenge)
{
    ifstream text(name);
    string word;
    string w;
    QString _word;

    while(getline(text,w))
        word += w + "\n";   //添加换行符

    _word = QString::fromStdString(word);

     QString jiequ;
     jiequ= _word.section(fenge,Tsum,Tsum);
     SG_UI::UI_OTextUi(jiequ);
     if(Tsum == DoneSum)    //如果文本输出完毕
     {
        //sgui->SG_OTextUi("#DONE#");
        //FU_ClearTextui();
        Tsum = 0;
     }
     else
        Tsum++;            //如果没输出完 将文本计数变量自加


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

void Figure::OpenSql(const QString SqlName)
{
    db.setDatabaseName(SqlName);    //设置数据库名字
    if(!db.open())                  //判断是否打开数据库 
        { /*错误界面*/}

    query = new QSqlQuery;          //初始化数据库操作变量

}

void Figure::CloseSql()
{
    db.close();                     //关闭数据库
}

QString* Figure::FindSql(QString TableName,QString FindName)
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

QString Figure::ReadSql(QString *ReadStr, int Sum)  //接受参数数组
{
    data = new QString[11];
    QString Error = "错误:Sum超出范围";
    data = ReadStr;
    if(Sum < 0 || Sum > 11)                                 //判断Sum范围(这个Sum从0到11对应着人物的参数)详情请看数据库
        return Error;
    else
        return data[Sum];
}

QString Figure::ReadSql(QString Name, QString DataName)
{
    OpenSql("SG.db");
    QString id ;
    QString ming = "SELECT * FROM SG WHERE NAME LIKE '"+ Name +"%'";
    QString mingg = "SELECT * FROM DS WHERE NAME LIKE '"+ Name +"%'";

    QString re;
    query->exec(ming);
    //检查名字是否在我方(SG)
    while(query->next())
         id = query->value(0).toString();       //通过名字查找对应的ID

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
              id = query->value(0).toString();

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

QString Figure::FigureShow(QString Name)
{
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
         id = query->value(0).toString();

    if(id == "")                            //如果不在SG中 则查看是否在DS中
    {
        query->exec(mingg);
        while(query->next())
            id = query->value(0).toString();

        if(id != "")                        //如果在DS中
            {
                Dy =  DSxy*Dy;                  //设置人物Y坐标
                QString _Name = ":/SG/Figure/little/" + Name+"_名片.png";
                SG_UI::UI_FigureShow(_Name,Name,"DS",Dx,Dy,803,Dy);//显示人物
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
        SG_UI::UI_FigureShow(_Name,Name,"SG",Sx,Sy,0,Sy);
        SGxy++;
        Sy = 78;
        //Table[tablsum] = "SG";
    }

}

QString Figure::CheckTable(QString Name)
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

        if(id != "")
            {
                ta = "DS";                     //如果在DS中
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

Figure* Figure::ReadFigureData(QString Name)
{
    Figure* FigureData = new Figure();
    FigureData->ID = this->ReadSql(Name,"ID").toInt();
    FigureData->HP = this->ReadSql(Name,"HP").toInt();
    FigureData->LV = this->ReadSql(Name,"LV").toInt();
    FigureData->AA = this->ReadSql(Name,"AA").toInt();
    FigureData->ATK  = this->ReadSql(Name,"ATK").toInt();
    FigureData->NAME = this->ReadSql(Name,"NAME");
    FigureData->ARMOR = this->ReadSql(Name,"ARMOR").toInt();
    FigureData->CLASS = this->ReadSql(Name,"CLASS");
    FigureData->DODGE = this->ReadSql(Name,"DODGE").toInt();
    FigureData->PLANESUM = this->ReadSql(Name,"PLANESUM").toInt();
    FigureData->TORPEDO  = this->ReadSql(Name,"TORPEDO").toInt();

    return FigureData;
}

int Figure::FightAtt(QString SG_, QString DS_,ParametersStru WeaponType) //默认第一个参数是攻击方,第二个为被攻击方,第三个是武器类型 返回剩余血量
{
    Figure* A = new Figure();
    A = ReadFigureData(SG_);
    Figure* B = new Figure();
    B = ReadFigureData(DS_);

    srand(time(0));
    double sh = (rand() % 100)*0.01+1;
    sh = round(sh*100)/100.0;

    int shjs = 0;
    QString ak = WeaponType.StringVar[0];
    //判断级别 用不同级别的伤害公式计算伤害
    if(A->CLASS == "CV"){//(我方攻击力+我方飞机数*级别系数 + 我方等级*级别系数)*随机伤害系数 -敌方装甲* 级别系数-敌方等级* 级别系数
        int cv = 0.6;
        double cvsh;
        if(ak == "CVMG")
             cvsh = (A->ATK + (A->LV* cv)* sh - (B->ARMOR + B->LV)* cv);
        else if(ak == "CVHZ")
             cvsh = (A->ATK + (A->PLANESUM + A->LV)* cv* sh - (B->ARMOR + B->LV)* cv);
        else if(ak == "CVTP")
             cvsh = (A->ATK + (A->PLANESUM + A->LV)* cv* sh - (B->ARMOR + B->LV)* cv);

        shjs = abs(cvsh);
    }
    else if(A->CLASS == "BB"){
        int bb = 0.7;
        double bbsh;
        if(ak == "BBMG")
             bbsh = (A->ATK + A->LV* bb)* sh - (B->ARMOR* bb + B->LV* bb);
        else bbsh = (A->ATK* bb)* sh - (B->ARMOR* bb + B->LV* bb);
        shjs = bbsh;
    }
    else if(A->CLASS == "BC"){
        int bc = 0.65;
        double bcsh;
        if(ak == "BCMG")
            bcsh = (A->ATK + A->LV* bc)*sh - (B->ARMOR* bc + B->LV* bc);
        else bcsh = (A->ATK* bc)*sh - (B->ARMOR* bc + B->LV* bc);
        shjs = bcsh;
    }
    else if(A->CLASS == "CA"){
        int ca = 0.55;
        double cash;
            if(ak == "CAMG")
                 cash = (A->ATK + A->LV* ca)*sh - (B->ARMOR* ca + B->LV* ca);
            else cash = (A->ATK)*sh - (B->ARMOR* ca +B->LV* ca);
            shjs = cash;
    }
    else if(A->CLASS == "CL"){
        int cl = 0.45;
        double clsh;
            if(ak == "CLMG")
                 clsh = (A->ATK + A->LV* cl +A->TORPEDO* 0.55)*sh - (B->ARMOR* cl + B->LV*cl);
            else
                 clsh = (A->ATK + A->LV)*sh - (B->ARMOR* cl + B->LV*cl);
                shjs = clsh;
    }
    else if(A->CLASS == "DD"){
        int dd = 0.4;
        double ddsh;
            if(ak == "DDMG")
                ddsh = (A->ATK + A->LV*dd + A->TORPEDO* 0.65)*sh - (B->ARMOR* dd + B->LV*dd);
            else
                ddsh = (A->ATK + A->LV)*sh - (B->ARMOR* dd + B->LV*dd);
        shjs = ddsh;
    }
    else if(A->CLASS == "SS"){
        int ss = 0.35;
        double sstp;
            if(ak == "SSMG")
                sstp = (A->ATK + A->LV)*ss*sh - (B->ARMOR* ss + B->LV*ss);
            else
                sstp = (A->ATK + A->LV*ss +A->TORPEDO* 0.75)*sh - (B->ARMOR* ss + B->LV*ss);
        shjs = sstp;
    }
    else
    {return 8888;}
    SG_UI::UI_AnimationFigure(SG_,DS_,abs(shjs),WeaponType);
    SG_UI::UI_ArticleBlood(WeaponType.ItemVar[0],WeaponType.intVar[0],WeaponType.intVar[1],B->HP-abs(shjs),B->HP);
    return B->HP - abs(shjs);
}

void Figure::PixToAscii(QString pach, QString Pixname, int Z)
{
    QImage* img = new QImage(pach+Pixname);
    QString ch[11] = {"@","#","&","Q","C","o","*",",",".","`"," "};
    map<int,QString> M;
        for(int i=0; i<256;i++){
        int in = i/25;
        M[i] = ch[in];
    }
    QFile my("ASCII.txt");
    my.open(QIODevice::WriteOnly);
    if(Z == 0)
        {
            if(img->width()<=150 || img->height()<=150)
                img->scaled(img->width()*2,img->height()*2);
            else if((img->width()>=900 || img->height()>=900))
                img->scaled(img->width()/2,img->height()/2);
    }

    for(int i = 0; i<img->height();i+=1)
        for(int j = 0; j<img->width();j+=1)
            {
                QColor c = img->pixel(j,i);
                int R = c.red();
                int G = c.green();
                int B = c.blue();
                int gary = (R*30 + G*59 +B*11)/100;
                if(M.find(gary) != M.end())
                my.write(M.find(gary)->second.toLatin1().data());
        }
}
