#include "sg_function.h"
#include "sg_ui.h"

extern int Sum;
extern int _Sum;
extern int Tbx;
int DoneSum = 7;
int Tsum =0;
extern SG_UI* sgui;
SG_Function* sgfu;

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

void SG_Function::SG_Return()
{

    int _Sum_ = _Sum;


    for(int i =Sum;_Sum_ >= i; _Sum_--)
    {
        fn->DeleteItem(fn->AllItem[_Sum_]);
    }

    if(_Sum == 36 && Sum == 24)
    {
        _Sum = 23;
        Sum = 11;

    }

    Tbx = 752;
}


void SG_Function::SG_ReadText(string name, QString fenge)
{
    ifstream text(name);
    string word;
    string w;
    QString _word;

    while(getline(text,w))
    {
        word += w + "\n";
    }
    _word = QString::fromStdString(word);

     QString jiequ;
     jiequ= _word.section(fenge,Tsum,Tsum);
     //sgui->SG_OTextUi(jiequ);
     fn->AddTextItem(jiequ,"微软雅黑",20,0,0,0,0,0);
     if(Tsum == DoneSum)
     {
        //sgui->SG_OTextUi("#DONE#");
        //FU_ClearTextui();
        Tsum = 0;
     }
     else
     {
         Tsum++;
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

