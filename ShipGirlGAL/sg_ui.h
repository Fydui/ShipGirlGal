#ifndef SG_UI_H
#define SG_UI_H
#include "library.h"
namespace UI {

    void UI_Main();
    void UI_CGame();
    void UI_Start();
    void UI_Return();
    void UI_StoryReturn();
    Item* UI_MainBackGround(Item* name, QString findname);
    void UI_MainStory();
    Item *UI_MainFigure(Item* name, QString findname);
    const QString BG = ":/Data/Image/Background/";
    const QString BU = ":/Data/Image/Button/";
    const QString LO = ":/Data/Image/Loop/";
}

#endif // SG_UI_H
