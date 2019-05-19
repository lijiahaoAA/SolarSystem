#include "SolorSystemWin.h"
#include <QApplication>
//函数入口
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//创建名为a 的QApplication对象
    SolorSystemWin w;//创建SolorSystemWin对象
    w.showMaximized();//showMaximized（）使SolorSystemWin窗口最大化
    return a.exec();//返回执行结果
}
