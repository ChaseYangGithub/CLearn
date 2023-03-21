#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include<QPushButton>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = 0);

    //构造函数  默认图片 按下后显示的图片(不一定有)
    MyPushButton(QString nomalImage,QString secondImage=" ");
    //弹跳函数--向下
    void bounceDown();
    //弹跳函数--向上
    void bounceUp();
    //鼠标点击按键
    void mousePressEvent(QMouseEvent *e);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *e);

//    //绘制圆形图片
//    void drawRoundIcon();
    //成员属性保存图片默认显示路径及按下后
    QString nomalImagePath;
    QString secondImagePath;
signals:

public slots:

};

#endif // MYPUSHBUTTON_H
