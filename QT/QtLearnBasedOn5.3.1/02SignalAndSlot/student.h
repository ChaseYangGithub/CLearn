#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = 0);

signals:

public slots:
    //早期槽函数必须写到public slots，Qt5之后高级版本可以写在public或者全局下
    //返回值void 需要声明 也需要实现
    //可以有参数，可以发生重载
    void treat();
    //重载
    void treat(QString foodName);
};

#endif // STUDENT_H
