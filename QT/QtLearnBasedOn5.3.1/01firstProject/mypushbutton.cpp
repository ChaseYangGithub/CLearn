#include "mypushbutton.h"
#include<QDebug>//用于控制台调试
MyPushButton::MyPushButton(QWidget *parent) :
    QPushButton(parent)
{
    qDebug()<<"我的按钮类构造函数";
}

MyPushButton::~MyPushButton(){
    qDebug()<<"我的按钮类析构函数";


}
