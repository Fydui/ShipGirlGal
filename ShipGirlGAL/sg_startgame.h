#ifndef SG_STARTGAME_H
#define SG_STARTGAME_H
#include "library.h"
class SG_StartGame  //: public QObject
{
public:
    SG_StartGame(library* s);
    void SG_StartUI();

private:
    library* sl;
    const QString SG =  ":/SG/Background/";
    const QString ST = ":/SG/startgame/";
};

#endif // SG_STARTGAME_H
