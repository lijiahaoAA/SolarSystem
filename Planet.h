#ifndef PLANET_H
#define PLANET_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QRectF>
#include <QTimerEvent>
#include <QObject>

class Planet:public QObject,public QGraphicsPixmapItem
{
public:
    Planet(QGraphicsItem *parent = nullptr);
    Planet(const QPixmap & pixmap,qreal _orbit,qreal  _revolution,QGraphicsItem * parent = nullptr);
    void setOrbitRadius(qreal value);
    void setRevolution(qreal value);
    void setSelfRadius(qreal value);
    void setAnglePerSec();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void timerEvent(QTimerEvent *);//设置时间

private://设置为qreal（double类型）
    qreal orbitRadius;//轨道半径
    qreal selfRadius;//自身半径
    qreal anglePerSec;//每秒走过的角度
    qreal revolutionPeriod;//公转周期
    qreal x{0.0},y{0.0};//坐标
    qreal currentAngle{0.0};//当前角度
};

#endif // PLANET_H
