#ifndef BULLET_H
#define BULLET_H
#include<QPixmap>

class Bullet
{
public:
    Bullet();
    //更新子弹坐标
    void updatePosition();
public:
    QPixmap bullet;//子弹资源对象
    //子弹坐标
    int x;
    int y;
    int speed;//子弹移动速度
    bool free;//闲置
    QRect rect;//子弹矩形碰撞检测狂
};

#endif // BULLET_H
