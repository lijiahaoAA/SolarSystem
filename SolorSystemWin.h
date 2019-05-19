#ifndef SOLORSYSTEMWIN_H
#define SOLORSYSTEMWIN_H

#include <QMainWindow>
#include <QGraphicsScene>
//定义Ui命名空间
namespace Ui {
class SolorSystemWin;
}

class SolorSystemWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit SolorSystemWin(QWidget *parent = nullptr);//parent只能显示转换类型
    ~SolorSystemWin();//析构函数

protected slots://槽中插入组件
    void slot_rotate(int);//整个系统进行旋转
    void slot_scale(int);//对整个系统进行放大
    void slot_shear(int);//扭曲变换

private slots://自动生成
    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

private:
    Ui::SolorSystemWin *ui;
    QGraphicsScene *scene;//定义scene，方便item放入scene容器中
    int currentAngle{0};//整个系统当前角度
    int currentScaleValue{0};//整个系统当前大小
    int currentShearValue{0};//整个系统当前观测方向（三位角度）
};

#endif // SOLORSYSTEMWIN_H
