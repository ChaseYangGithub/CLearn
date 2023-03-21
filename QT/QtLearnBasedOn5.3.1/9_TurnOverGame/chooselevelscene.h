#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "gamescene.h"
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = 0);
    //重写绘图事件
    void paintEvent(QPaintEvent *);

    //具体关卡场景
    GameScene *gameScene=NULL;
signals:
    //自定义信号告诉主场景点击了返回按钮  自定义信号只需声明不需实现
    void chooseSceneBack();
public slots:

};

#endif // CHOOSELEVELSCENE_H
