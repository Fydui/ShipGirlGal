#include "sg_startgame.h"
#include "sg_ui.h"
SG_StartGame* ss;
//extern SG_UI* sgui;
using namespace std;
SG_StartGame::SG_StartGame(library* s)
{
    sl = s;

}


void SG_StartGame::SG_StartText()
{
    //sl->AddMouseEvent();
    SG_FileOpen("1_1.text","#",10);
}

QString SG_StartGame::SG_FileOpen(string name, string fenge, int sum)
{
    ifstream infile(name);
    string word = "";
    string tem;
    while(getline(infile,tem))
    {
        word += tem+"\n";
    }
    vector<string>Str_list;
    int conna_n = 0;
    while (1)
    {
        string tem_s = "";

        conna_n = word.find(fenge);
        if(conna_n == -1)
        {
            Str_list.push_back(word);
            break;
        }
        tem_s = word.substr(0,conna_n + fenge.length());
        Str_list.push_back(tem_s);
    }
    string wordss;
    QString WORD;
    for(int i = 0; i < sum; i++)
    {
        wordss = Str_list.at(i);
        WORD = QString::fromStdString(wordss);
        return WORD;
    }
}
