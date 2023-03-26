#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include<QTimer>
#include "map.h"
#include "heroplane.h"
#include "enermyplane.h"
#include "bomb.h"
class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    //初始化场景
    void initScene();
    //启动游戏 用于启动计时器对象
    void playGame();
    //更新坐标
    void updatePosition();
    //重写绘图时间
    void paintEvent(QPaintEvent *e);
    //重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent *);
    //敌机出现
    void enermyToScene();
    //碰撞检测
    void collisionDetection();
    ~MainScene();
public:
    QTimer m_timer;//定时器用于地图运动
    Map map;//地图对象 注意包含头文件
    HeroPlane hero;//英雄飞机对象
    EnermyPlane enermys[ENERMY_NUM];//敌机数组
    int record;//敌机出现间隔--配合主场景的计时器使用
    Bomb bombs[BOMB_NUM];


    //测试代码
//    Bullet temp_bullet;//测试子弹代码


};
#endif // MAINSCENE_H
