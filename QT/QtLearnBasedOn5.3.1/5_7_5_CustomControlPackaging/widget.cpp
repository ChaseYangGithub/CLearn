#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //建立连接显示当前值
    connect(ui->btn_showNum,&QPushButton::clicked,[=](){//CONFIG+=c++11
            //此时对应子控件类名为Widget
       qDebug()<< ui->widget->getNum();
    });
    //建立连接设置为指定值
    int num=50;
    connect(ui->btn_setHalfNum,&QPushButton::clicked,[=](){//CONFIG+=c++11
            //此时对应子控件类名为Widget
        ui->widget->setNum(num);
    });
}
Widget::~Widget()
{
    delete ui;
}
