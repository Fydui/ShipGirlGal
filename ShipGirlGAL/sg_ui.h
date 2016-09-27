#ifndef SG_UI_H
#define SG_UI_H
#include "library.h"
namespace UI {

    void UI_Main();
    void UI_CGame();
    void UI_Start(QString slotname, VoidSlot slot);
    void UI_Return();
    void UI_StoryReturn();
    void UI_MainStory();
    void UI_FightFigure(QString figurename);
    void UI_FightFigure(QString* SGnames[], QString* DSnames[]);
    Item* UI_MainBackGround(Item* name, QString findname);
    Item* UI_MainFigure(Item* name, QString findname);
    const QString BG = ":/Data/Image/Background/";
    const QString BU = ":/Data/Image/Button/";
    const QString LO = ":/Data/Image/Loop/";
}

#endif // SG_UI_H
