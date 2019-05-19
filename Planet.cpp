#include "Planet.h"
#include <QPainter>
#include <qmath.h>
//构造函数
Planet::Planet(QGraphicsItem *parent):QGraphicsPixmapItem(parent),orbitRadius(0),selfRadius(0),anglePerSec(0),revolutionPeriod(0)
{

}
Planet::Planet(const QPixmap &pixmap, qreal _orbit,qreal _revolution,QGraphicsItem *parent):QGraphicsPixmapItem(pixmap,parent)
{
    setSelfRadius(pixmap.width() >> 1);
    setOrbitRadius(_orbit);
    setRevolution(_revolution);
    setAnglePerSec();
    x = 0 - selfRadius / 2;
    y = orbitRadius - selfRadius / 2;
    startTimer(10);//设置行星公转延迟（速度）
}
QRectF Planet::boundingRect() const//设置行星运转轨道（与轨道保持一致即可）
{
    return QRectF(-1 - selfRadius,-1 - selfRadius,2 * selfRadius,2 * selfRadius);
}
void Planet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect().topLeft(),pixmap());//在矩形boundingRect中的topLeft绘制像素映射pixmap。

}
void Planet::timerEvent(QTimerEvent *)
{
    setPos(x,y);
    currentAngle += anglePerSec;
    x = orbitRadius * sin(currentAngle / 180);
    y = orbitRadius * cos(currentAngle / 180);
}

void Planet::setOrbitRadius(qreal value)
{
    orbitRadius = value;
}
void Planet::setSelfRadius(qreal value)
{
    selfRadius = value;
}
void Planet::setRevolution(qreal value)
{
    revolutionPeriod = value;
}
void Planet::setAnglePerSec()
{
    anglePerSec = 360.0 / (revolutionPeriod * 360 );//以地球公转周期为基准周期
}
