#include "Orbit.h"
#include <QPainter>
#include <QColor>
//构造方法
Orbit::Orbit(QColor _color,QGraphicsItem *parent):QGraphicsEllipseItem(parent),color(_color),x(),y(),width(),height()
{
}
Orbit::Orbit(QColor _color, int _x, int _y, int _width, int _height, QGraphicsItem *parent):Orbit(_color,parent)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
}
QRectF Orbit::boundingRect() const
{
    return QRectF(-1 - width / 2,-1 - height / 2,width,height);//画框的大小
}
void Orbit::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::NoBrush);//刷子
    painter->setPen(color);//画笔颜色
    painter->drawEllipse(boundingRect());//画圆，即轨道
}
