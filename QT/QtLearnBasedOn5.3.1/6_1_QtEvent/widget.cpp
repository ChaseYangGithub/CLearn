#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
#include<QMouseEvent>
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    id1= startTimer(1000);//参数 时间间隔，单位毫秒
    id2=startTimer(2000);//参数 时间间隔，单位毫秒

    //定时器的第二种方式QTimer
    QTimer *timer=new QTimer(this);
    //启动定时器
    timer->start(500);
    connect(timer,&QTimer::timeout,[=](){
        static int num4=1;
        //每500毫秒加一
        ui->label_time3->setText(QString::number(num4++));
    });
    //按钮暂停
    connect(ui->btn_pause,&QPushButton::clicked,[=](){
        static bool flag=false;
        if(!flag){
            timer->stop();
            flag=true;
        }else{
            timer->start();
            flag=false;
        }

    });

    //myPushButton安装事件过滤器
    //安装事件过滤器
    ui->pushButton->installEventFilter(this);
    //重写eventfilter事件
}
//重写事件过滤器的事件
bool Widget::eventFilter(QObject *obj, QEvent *e){
    //控件判断
    if(obj==ui->pushButton){
        if(e->type()==QEvent::MouseButtonPress){
            //类型转化
            QMouseEvent *ev=static_cast<QMouseEvent *>(e);
            QString str2=QString("事件过滤器 鼠标点击x=%1 y=%2").arg(ev->windowPos().x()).arg(ev->y());
            qDebug()<<str2;
            //返回true代表自己处理
            return true;
        }
    }
    //其他默认处理
    return QWidget::eventFilter(obj,e);

}

//重写定时器事件
void Widget::timerEvent(QTimerEvent *e){
    if(e->timerId()==id1){
         static int num=1;
         //1
         ui->label_time->setText(QString::number(num++));
    }
   if(e->timerId()==id2){

    static int num2=1;
    //2
    ui->label_time2->setText(QString::number(num2++));
   }

}
Widget::~Widget()
{
    delete ui;
}
