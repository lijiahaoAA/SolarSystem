#include "SolorSystemWin.h"
#include "ui_SolorSystemWin.h"
#include "Orbit.h"
#include "Planet.h"
#include <QColor>
#include <QPalette>
#include <QPixmap>
#include <QBitmap>
#include <QDebug>
#include <QGraphicsPixmapItem>

SolorSystemWin::SolorSystemWin(QWidget *parent) :
    QMainWindow(parent),//调用SolorSystemWin的父类QMainWindow构造函数
    ui(new Ui::SolorSystemWin),//ui为初始化SolorSystemWin的界面
    scene(new QGraphicsScene())//自定义添加item容器
    {
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAutoFillBackground(true);//自动填充背景
    //设置背景颜色
    QColor backColor = QColor(Qt::black);
    backColor.setAlphaF(0.7);
    QPalette p = ui->graphicsView->palette();//调色板color role
    p.setColor(ui->graphicsView->backgroundRole(),backColor);
    ui->graphicsView->setPalette(p);
    //添加所有轨道item
    scene->addItem(new Orbit(QColor(Qt::yellow),0,0,80,80));
    scene->addItem(new Orbit(QColor(Qt::yellow),0,0,105,105));
    scene->addItem(new Orbit(QColor(Qt::yellow),0,0,145,145));
    scene->addItem(new Orbit(QColor(Qt::yellow),0,0,190,190));
    scene->addItem(new Orbit(QColor(Qt::yellow),0,0,240,240));
    scene->addItem(new Orbit(QColor(Qt::yellow),0,0,300,300));
    scene->addItem(new Orbit(QColor(Qt::yellow),0,0,450,450));
    scene->addItem(new Orbit(QColor(Qt::yellow),0,0,600,600));

    QGraphicsPixmapItem *sun = new QGraphicsPixmapItem(QPixmap(":/image/image/sun.png"));
    scene->addItem(sun);//太阳在中心
    sun->setPos(-30,-30);//设置太阳坐标
    //显示图片
    QPixmap earthPix(":/image/image/earth.png");
    QPixmap mercuryPix(":/image/image/mercury.png");
    QPixmap venusPix(":/image/image/venus.png");
    QPixmap marsPix(":/image/image/mars.png");
    QPixmap jupiterPix(":/image/image/jupiter.png");
    QPixmap saturnPix(":/image/image/saturn.png");
    QPixmap uranusPix(":/image/image/uranus.png");
    QPixmap neptunePix(":/image/image/neptune.png");
    //初始化行星对象
    Planet *mercury = new Planet(mercuryPix,40,0.24);
    Planet *venus = new Planet(venusPix,52.5,0.62);
    Planet *earth = new Planet(earthPix,72.5,1);
    Planet *mars = new Planet(marsPix,95,1.9);
    Planet *jupiter = new Planet(jupiterPix,120,11.8);
    Planet *saturn = new Planet(saturnPix,150,29.5);
    Planet *uranus = new Planet(uranusPix,225,84);
    Planet *neptune = new Planet(neptunePix,300,164.8);
    //添加行星组件道容器中
    scene->addItem(mercury);
    scene->addItem(venus);
    scene->addItem(earth);
    scene->addItem(mars);
    scene->addItem(jupiter);
    scene->addItem(saturn);
    scene->addItem(uranus);
    scene->addItem(neptune);
    //对月球进行单独处理
    Planet *moon = new Planet(QPixmap(":/image/image/moon.png"),15,0.083,earth);
    scene->addItem(moon);
    //和ui进行链接
    connect(ui->rotateSlider,SIGNAL(valueChanged(int)),this,SLOT(slot_rotate(int)));
    connect(ui->scaleSlider,SIGNAL(valueChanged(int)),this,SLOT(slot_scale(int)));
    connect(ui->shearSlider,SIGNAL(valueChanged(int)),this,SLOT(slot_shear(int)));

}

SolorSystemWin::~SolorSystemWin()
{
    delete ui;//释放内存
}
//自定义旋转变换
void SolorSystemWin::slot_rotate(int angle)
{
    ui->rotateLabel->setNum(angle);
    ui->graphicsView->rotate(angle - currentAngle);
    currentAngle = angle;
}
//自定义比例变换
void SolorSystemWin::slot_scale(int value)
{
    ui->scaleLabel->setNum(value);
    qreal s;
    if (value > currentScaleValue)
        s = pow(1.05,value - currentScaleValue);
    else s = pow(1/1.05,currentScaleValue - value);
    ui->graphicsView->scale(s,s);
    currentScaleValue = value;
}
//自定义扭曲变换
void SolorSystemWin::slot_shear(int value)
{
    ui->shearLabel->setNum(value);
    ui->graphicsView->shear((value - currentShearValue) / 10.0,0);
    currentShearValue = value;
}
//运行自动生成
void SolorSystemWin::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{

}
