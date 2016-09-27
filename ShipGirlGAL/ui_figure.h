#ifndef UI_FIGURE_H
#define UI_FIGURE_H
#include <sg_ui.h>
#include "head.h"

using namespace std;
class ui_figure
{
public:
    ui_figure();
    QString FindFigureData(QString figurename, QString figuredata);
    QString FindFigureTeam(QString figurename);

private:
    QString OpenSQl(QString SQLname);
    void CloseSQL();
    QSqlDatabase db;
    //QSqlQuery* sql;           //数据库操作指针
};

#endif // UI_FIGURE_H
