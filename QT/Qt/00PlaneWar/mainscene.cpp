#include "mainscene.h"
#include "config.h"//配置文件
#include<QIcon>//图标
#include<QPainter>
#include<QMouseEvent>
#include<ctime> //随机数
#include<QSound>//声音
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //调用初始化场景函数
    this->initScene();
    //开始游戏
    this->playGame();
}


//初始化场景
void MainScene::initScene()
{
    //初始化窗口大小
    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //设置窗口标题
    this->setWindowTitle(GAME_TITLE);
    //游戏图标
    this->setWindowIcon(QIcon(GAME_ICON));//加头文件 #include <QIcon>
    //设置计时器间隔
    this->m_timer.setInterval(GAME_RATE);
    //初始化敌机出现间隔
    record=0;
    //设置随机数种子
    srand((unsigned int)time(NULL));//注意添加头文件
}

//启动游戏 用于启动计时器对象
void MainScene::playGame()
{
    //播放背景音乐
    QSound::play(SOUND_BACKGROUND);
    //启动定时器
    m_timer.start();

    //监听计时器 用于刷新地图
    connect(&m_timer,&QTimer::timeout,this,[=](){

        //敌机出现
        enermyToScene();
        //更新游戏中元素的坐标
        updatePosition();
        //重新绘制图片
        update();
        //碰撞检测
        collisionDetection();
    });

}
//更新坐标
void MainScene::updatePosition()
{
    //更新地图坐标
    map.mapPosition();

    //测试子弹代码
    //    temp_bullet.free=false;
    //    temp_bullet.updatePosition();

    //发射子弹
    hero.shoot();
    //计算子弹坐标
    for(int i=0;i<BULLET_NUM;i++){
        //如果子弹为非空闲状态，计算发射位置
        if(!hero.bullets[i].free){
            hero.bullets[i].updatePosition();
        }
    }
    //计算敌机坐标
    for(int i=0;i<ENERMY_NUM;i++){
        if(enermys[i].free==false){
            enermys[i].updatePosition();
        }
    }
    //计算爆炸坐标
    for(int i=0;i<BOMB_NUM;i++){
        if(bombs[i].free==false){
            bombs[i].updateInfo();
        }
    }
}

//绘图事件
void MainScene::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,map.map1_posY,map.map1);
    painter.drawPixmap(0,map.map2_posY,map.map2);
    //绘制英雄飞机
    painter.drawPixmap(hero.x,hero.y,hero.m_plane);
    //测试子弹代码
    //painter.drawPixmap(temp_bullet.x,temp_bullet.y,temp_bullet.bullet);

    //绘制子弹
    for(int i=0;i<BULLET_NUM;i++){
        //如果子弹状态为false计算发射位置
        if(!hero.bullets[i].free){
            painter.drawPixmap(hero.bullets[i].x,hero.bullets[i].y,hero.bullets[i].bullet);
        }
    }

    //绘制敌机
    for(int i=0;i<ENERMY_NUM;i++){
        if(!enermys[i].free){
            painter.drawPixmap(enermys[i].x,enermys[i].y,enermys[i].enermy);
        }
    }

    //绘制爆炸图片

    for(int i=0;i<BOMB_NUM;i++){
        if(bombs[i].free==false){
            painter.drawPixmap(bombs[i].x,bombs[i].y,bombs[i].pix[bombs[i].index]);
        }
    }


}
//重写鼠标移动事件  注意包含头文件
void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    //记录鼠标坐标
    int x=event->x()-hero.m_rect.width()*0.5;//鼠标位置减去碰撞检测矩形位置的一半
    int y=event->y()-hero.m_rect.height()*0.5;//鼠标位置减去碰撞检测矩形位置的一半

    //边界检测
    if(x<=0){
        x=0;
    }
    if(x>GAME_WIDTH-hero.m_rect.width()){
        x=GAME_WIDTH-hero.m_rect.width();
    }
    if(y<=0){
        y=0;
    }
    if(y>=GAME_HEIGHT-hero.m_rect.height()){
        y=GAME_HEIGHT-hero.m_rect.height();
    }
    hero.setPosition(x,y);
}
//敌机出现
void MainScene::enermyToScene()
{
    record++;
    //如果没到达间隔时间（record*timer.interval) 直接返回
    if(record<ENERMY_INTERVAL){
        return;
    }
    //到达重置间隔
    record=0;
    //敌机出现
    for(int i=0;i<ENERMY_NUM;i++){
        if(enermys[i].free){//如果为空闲
            //敌机的空闲状态改为false
            enermys[i].free=false;
            //设置坐标
            enermys[i].x=rand()%(GAME_WIDTH-enermys[i].rect.width());
            enermys[i].y=-enermys[i].rect.height();
            break;
        }

    }

}
//碰撞检测
void MainScene::collisionDetection()
{
    //实现方式，遍历所有飞机和子弹，如果发生碰撞，释放为free
    //遍历所有非空闲飞机
    for(int i=0;i<ENERMY_NUM;i++){
        if(enermys[i].free){
            //空闲飞机进入下一次循环
            continue;
        }
        //遍历所有非空闲的子弹
        for(int j=0;j<BULLET_NUM;j++){
            if(hero.bullets[j].free){
                continue;
            }
            //如果相交，发生碰撞 同时变为空闲状态
            if(enermys[i].rect.intersects(hero.bullets[j].rect)){
                //播放爆炸效果
                QSound::play(SOUND_BOMB);//播放爆炸声
                enermys[i].free=true;
                hero.bullets[j].free=true;

                for(int k=0;k<BOMB_NUM;k++){
                    if(bombs[k].free){
                        //爆炸状态设置为非空闲
                        bombs[k].free=false;
                        //更新坐标
                        bombs[k].x=enermys[i].x;
                        bombs[k].y=enermys[i].y;
                        break;
                    }
                }
            }
        }
    }
}

MainScene::~MainScene()
{
}

