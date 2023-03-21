#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = 0);

signals:
        //自定义信号写到signals下
        //返回值为void，只需要声明，不需要实现，可以有参数,可以重载
        void  hungry();
        //重载
        void hungry(QString foodName);//Qt中使用Qstring表示string
public slots:

};

#endif // TEACHER_H
