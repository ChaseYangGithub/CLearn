#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <QPushButton>
#include<QTimer>
class MyImage : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyImage(QWidget *parent = 0);
    //参数代表传入的图片路径
    MyImage(QString btnImg);

    //改变标志的方法
    void changeFlag();
    //根据标志位判断鼠标按下事件是否有效--与在changeFlag中判断等价
    void mousePressEvent(QMouseEvent *e);

    QTimer *timer1;//正面的计时器
    QTimer *timer2;//反面的计时器
    int min=1;//最小值
    int max=8;//最大值
    //图片属性
    int x;//x坐标
    int y;//y坐标
    bool flag;//正反面
    int level;//存储关卡等级
    bool isAnimation=false;//执行动画标志位
    bool win=false;//赢
    //禁用允许按钮
    bool enable=false;
signals:

public slots:

};

#endif // MYIMAGE_H
