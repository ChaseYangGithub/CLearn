#ifndef ENERMYPLANE_H
#define ENERMYPLANE_H

#include<QPixmap>
#include<QRect>
class EnermyPlane
{
public:
    EnermyPlane();
    //更新坐标
    void updatePosition();
public:
    //低级资源对象
    QPixmap enermy;
    //位置
    int x;
    int y;

    //敌机的边距检测
    QRect rect;
    //状态，与子弹类似
    bool free;
    //速度
    int speed;
};

#endif // ENERMYPLANE_H
