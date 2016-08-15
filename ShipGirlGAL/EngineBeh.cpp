//-----本文件是引擎行为层给引擎调用的函数的实现-----
#include "widget.h"

bool Widget::isColliding(QGraphicsItem* RItem1, QGraphicsItem* RItem2)
{return bool(RItem1->QGraphicsItem::collidesWithItem(RItem2));}

QPixmap* Widget::mirrorAndChange(QPixmap *pixmap,bool mirrorMode)
{
    QImage img=pixmap->toImage();
    if(mirrorMode)//真为水平
    {img=img.mirrored(1,0);}
    else
    {img=img.mirrored(0,1);}
    QPixmap *newpix=new QPixmap;
    *newpix=QPixmap::fromImage(img);
    return newpix;
}
