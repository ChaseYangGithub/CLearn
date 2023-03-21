#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myPushButton(QWidget *parent = 0);
    //鼠标进入事件
    void enterEvent(QEvent *) ;
    //鼠标离开事件
    void leaveEvent(QEvent *);
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *e);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *e);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *e);
    //通过event事件分发器 拦截鼠标按下事件
    bool event(QEvent *e);
signals:

public slots:

};

#endif // MYPUSHBUTTON_H
