#ifndef SG_UI_H
#define SG_UI_H
#include "library.h"
namespace UI {

    void UI_Main();
    void UI_CGame();
    void UI_Start(QString slotname, VoidSlot slot);
    void UI_Start();
    void UI_Return();
    void UI_StoryReturn();
    void UI_MainStory();
    void UI_FightFigure(QString figurename);
    void UI_FightFigure(QString SGname[], QString DSname[]);
    Item* UI_SetBackGround(Item* name, QString findname);
    Item* UI_SetText(Item* name, QString findname);
    Item* UI_SetFigure(Item* name, QString findname);
    void UI_SetFigureTalk(QString ConfigFileName);
    void UI_SetFigureTalk(QString figurename, QString Talk);
    void UI_ParsingConfig(QString ConfigFileName);
    const QString BG = ":/Data/Image/Background/";
    const QString BU = ":/Data/Image/Button/";
    const QString LO = ":/Data/Image/Loop/";
}

#endif // SG_UI_H
