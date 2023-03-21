#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include "chooselevelscene.h"//选择关卡场景
namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    //重写paintEvent事件 绘图
    void paintEvent(QPaintEvent *);
    //关卡场景
    ChooseLevelScene *chooseLevelScene=NULL;
    ~MainScene();

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
