#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QMainWindow>
#include "gamescene.h"
#include "myimage.h"
class GameScene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit GameScene(QWidget *parent = 0);
    //构造函数 默认参数为游戏关卡
    GameScene(int levelNum);
    //重写paintEvent事件
    void paintEvent(QPaintEvent *);


    //判断是否胜利
    bool isWin();
    //内部成员属性 记录关卡
    int levelIndex;
    //二维数组用于维护每关的具体数据
    int gameArray[4][4];
    //关卡中所有按钮指针
    MyImage *imagePoint[4][4];
signals:
    //具体关卡返回信号
    void chooseSceneBack();
public slots:

};

#endif // GAMESCENE_H
