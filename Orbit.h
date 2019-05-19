#ifndef ORBIT_H
#define ORBIT_H

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QColor>
#include <QRectF>

class Orbit:public QGraphicsEllipseItem//继承
{
public://两个轨道方法，多态
    Orbit(QColor _color,QGraphicsItem *parent = nullptr);
    Orbit(QColor _color,int _x,int _y,int _width,int _height, QGraphicsItem *parent = nullptr);

protected://画布
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;//选取框尺寸

private://定义颜色，坐标，宽高
    QColor color;
    int x,y;
    int width;
    int height;
};

#endif // ORBIT_H
