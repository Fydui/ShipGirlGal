#ifndef SG_STARTGAME_H
#define SG_STARTGAME_H
#include "library.h"
#include <fstream>
#include <vector>
#include <string>
class SG_StartGame  /*对游戏的导演都在此类(一股面向过程味儿扑面而来)*/

{
public:
    SG_StartGame(library* s);
    //void SG_StartUI();
    void SG_StartText();

private:
    library* sl;
    const QString SG =  ":/SG/Background/";

};

#endif // SG_STARTGAME_H
