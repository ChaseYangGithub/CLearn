#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    //重写定时器事件
    void timerEvent(QTimerEvent *e);

    //重写事件过滤器的事件
    bool eventFilter(QObject *, QEvent *);
    ~Widget();
    int id1;//计时器标识
    int id2;//计时器标识

private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
