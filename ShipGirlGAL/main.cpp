//-----本文件无需修改-----
#include "widget.h"
#include "maincall.h"
#include <QApplication>

QObject *thob;
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //添加数据库驱动链接sqlite

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    maincall *m=new maincall;
    thob=m;
    m->QWidget::show();
    m->setMouseTracking(true); //在鼠标按下时响应跟踪
    m->StartGame(); //启动游戏
    return a.exec();
}
