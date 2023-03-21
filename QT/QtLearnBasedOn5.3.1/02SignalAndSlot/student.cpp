#include "student.h"
#include<QDebug>
Student::Student(QObject *parent) :
    QObject(parent)
{

}
//槽函数请老师吃饭
void Student::treat()
{
    qDebug()<<"请老师吃饭";
}
//重载版本
void Student::treat(QString foodName){
    //输出的字符串有"
    //将QString ->char*  先转化成QByteArray再转化成char*
    qDebug()<<"请老师吃饭，老师要吃"<<foodName.toUtf8().data();
}
