#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPixmap>
#include<QPainter>
#include<mypushbutton.h>//我的按钮
#include<QDebug>
#include<QTimer>//用于延时
#include<QSound>//多媒体  配置文件中要添加QT += multimedia
MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //配置主要大小
    //设置固定窗口大小
    this->setFixedSize(600,1020);
    //设置icon图标
    this->setWindowIcon(QPixmap(":/image/tuzi.jpg"));
    //设置应用标题
    this->setWindowTitle("图片翻转");

    //退出按钮的实现
    connect(ui->actionLoginOut,&QAction::triggered,[=](){//CONFIG+=c++11
        this->close();
    });
    //主场景开始音效
    QSound *startSound=new QSound(":/image/TapButtonSound.wav",this);

    //开始按钮
    MyPushButton *startBtn=new MyPushButton(":/image/start.png");
    //将按钮放入到当前窗口中
    startBtn->setParent(this);
    //移动按钮到中间偏下位置
    startBtn->move(QPoint(this->window()->width()*0.5-startBtn->width()*0.5,this->window()->height()*0.6));


    //实例化选择关卡场景--放在开始按钮信号前
    chooseLevelScene =new ChooseLevelScene;

    //开始按钮连接
    connect(startBtn,&QPushButton::clicked,[=](){
        //        qDebug()<<"开始按钮被点击了";
        //音效
        startSound->play();
        //按钮弹跳效果
        startBtn->bounceDown();
        startBtn->bounceUp();
        //        QTimer ::singleShot(500,this,[=]{}); 5.3不支持这种写法
        //延时到选择关卡场景
        QTimer* t = new QTimer(this);
        connect(t,&QTimer::timeout,[=](){
            t->stop();//停止计时
            t->deleteLater();//删除对象

            //设置为当前场景位置
            chooseLevelScene->setGeometry(this->geometry());

            //显示选择关卡场景
            chooseLevelScene->show();
            //隐藏自身
            this->hide();

        });
        t->start(50);//开始计时
    });

    //监听选择关卡的返回按钮的信号
    connect(chooseLevelScene,&ChooseLevelScene::chooseSceneBack,[=](){
        //设置为当前场景位置
        this->setGeometry(chooseLevelScene->geometry());
        //显示当前页面，隐藏关卡页面
        this->show();
        chooseLevelScene->hide();
    });
}

//重写paintEvent事件 绘图
void MainScene::paintEvent(QPaintEvent *){
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/image/background.png");
    //绘制背景图 设置为this.width可能会拉伸图片注意
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //绘制背景图标
    pix.load(":/image/title.png");
    //图片缩放
    pix= pix.scaled(pix.width()*0.6,pix.height()*0.6);
    painter.drawPixmap(10,30,pix);//后面画的图层在上面
}

MainScene::~MainScene()
{
    delete ui;
}
