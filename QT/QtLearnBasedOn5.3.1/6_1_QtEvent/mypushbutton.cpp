#include "mypushbutton.h"
#include<QDebug>
#include<QMouseEvent>
myPushButton::myPushButton(QWidget *parent) :
    QPushButton(parent)
{
    //设置鼠标追踪状态
    setMouseTracking(true);//只要鼠标移动就可以捕捉
}
//鼠标进入事件
void myPushButton::enterEvent(QEvent *) {
    qDebug()<<"鼠标进入";
}

//鼠标离开事件
void myPushButton::leaveEvent(QEvent *){
    qDebug()<<"鼠标离开";
}
//鼠标点击事件
void myPushButton::mousePressEvent(QMouseEvent *e){
    if(e->button()==Qt::LeftButton){//仅左键
        //%1 %2为对应参数位置，arg为每一个参数（arg为其静态方法，返回对应指针）
        //windowPos是整个窗口的位置，直接x y是当前控件对应的相对位置 GlobalX是屏幕分辨率的位置
        QString str=QString("鼠标点击x=%1 y=%2").arg(e->windowPos().x()).arg(e->y());
        qDebug()<<str;
    }
}

//鼠标释放事件
void myPushButton::mouseReleaseEvent(QMouseEvent *e){
    QString str=QString("鼠标释放x=%1  y=%2").arg(e->globalX()).arg(e->y());
    qDebug()<<str;
}

//鼠标移动事件
void myPushButton::mouseMoveEvent(QMouseEvent *e){
    if(e->buttons()&Qt::LeftButton){//在多按键操作中必须使用&判断枚举值
        QString str=QString("鼠标移动x=%1 y=%2").arg(e->x(),e->windowPos().y());
        qDebug()<<str;
    }
}

//通过event事件分发器 拦截鼠标按下事件
bool myPushButton::event(QEvent *e){
    //如果是鼠标的按下事件，在event事件分发中做拦截操作
    if(e->type()==QEvent::MouseButtonPress){
        QString str=QString("拦截鼠标按下");
        //类型转化
        QMouseEvent *ev=static_cast<QMouseEvent *>(e);
        QString str2=QString("Event鼠标点击x=%1 y=%2").arg(ev->windowPos().x()).arg(ev->y());
        qDebug()<<str;
        qDebug()<<str2;
        //返回true代表自己处理
        return true;
    }
    //其他事件交给父类处理
    return QPushButton::event(e);
}
