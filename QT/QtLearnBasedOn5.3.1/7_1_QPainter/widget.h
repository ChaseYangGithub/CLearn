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
    //绘图事件
    void paintEvent(QPaintEvent *);
    ~Widget();
    int posx=0;//图片x位置
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
