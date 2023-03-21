#include "mypushbutton.h"
#include<QPushButton>
#include<QDebug>
#include<QPropertyAnimation>//属性动画
#include<QPainter>
//默认图片 第二个图片(不一定有)  构造函数中有默认值，声明中则没有
MyPushButton::MyPushButton(QString nomalImage,QString secondImage){
    //设置成员属性值为指定路径
    this->nomalImagePath=nomalImage;
    this->secondImagePath=secondImage;

    QPixmap pix;
    //加载默认显示图片
    bool show =pix.load(nomalImage);
    //图片加载失败，结束程序
    if(!show){
        qDebug()<<"图片加载失败";
        return;
    }
    //设置图片为固定大小
    this->setFixedSize(pix.width()*0.5,pix.height()*0.5);
    //设置不规则图片样式   css
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width()*0.5,pix.height()*0.5));
}
//弹跳函数--向下
void MyPushButton::bounceDown(){
    //创建动画对象 对象是谁 那种特效
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    //设置动画间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置弹跳曲线--类似球落地反向
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

//弹跳函数--向上
void MyPushButton::bounceUp(){
    //创建动画对象 对象是谁 那种特效
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    //设置动画间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置弹跳曲线--类似球落地反向
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

//鼠标点击按键
void MyPushButton::mousePressEvent(QMouseEvent *e){
//    qDebug()<<"鼠标点击事件";

    //如果第二张图片不为空切换图片
    if(this->secondImagePath!=" "){
        QPixmap pix;
        //加载默认显示图片
        bool show =pix.load(this->secondImagePath);
        //图片加载失败，结束程序
        if(!show){
            qDebug()<<"图片加载失败";
            return;
        }
        //设置图片为固定大小
        this->setFixedSize(pix.width()*0.5,pix.height()*0.5);
        //设置不规则图片样式   css
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width()*0.5,pix.height()*0.5));
    }
    //父类执行其他内容
    return QPushButton::mousePressEvent(e);
}

//鼠标释放事件
void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
    //如果第二张图片不为空切换图片
    if(this->secondImagePath!=" "){
        QPixmap pix;
        //加载默认显示图片
        bool show =pix.load(this->nomalImagePath);
        //图片加载失败，结束程序
        if(!show){
            qDebug()<<"图片加载失败";
            return;
        }
        //设置图片为固定大小
        this->setFixedSize(pix.width()*0.5,pix.height()*0.5);
        //设置不规则图片样式   css
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width()*0.5,pix.height()*0.5));

    }
    //父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);
}

