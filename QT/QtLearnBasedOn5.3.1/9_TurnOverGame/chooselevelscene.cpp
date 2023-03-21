#include "chooselevelscene.h"
#include<QMenuBar>
#include<QPainter>
#include<QPixmap>
#include "mypushbutton.h"
#include<QDebug>
#include<QTimer>//用于延时
#include<QLabel>
#include<QFont>//字体
#include<QSound>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) :
    QMainWindow(parent)
{
    //设置固定窗口大小
    this->setFixedSize(600,1020);
    //设置icon图标
    this->setWindowIcon(QPixmap(":/image/tuzi.jpg"));
    //设置应用标题
    this->setWindowTitle("图片翻转");

    //选择关卡代码实现菜单栏
    QMenuBar *bar=menuBar();
    //只有一个的用set有多个的用add
    setMenuBar(bar);
    //创建开始菜单
    QMenu *startMenu=  bar->addMenu("菜单");
    //创建退出的菜单项
    QAction *quitAction= startMenu->addAction("退出");

    //点击退出
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    //使用自定义按钮实现返回按钮
    //返回按钮的两个图片
    QString img1=":/image/Back.png";
    QString img2=":/image/Back2.png";
    MyPushButton *backBtn=new MyPushButton(img1,img2);

    //将按钮显示到窗口中
    backBtn->setParent(this);
    //移动到右下角
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    //点击按钮返回
    connect(backBtn,&QPushButton::clicked,[=](){
        //        qDebug()<<"点击返回按钮";
        //延时操作
        QTimer *timer=new QTimer(this);
        //延时信号检测
        connect(timer,&QTimer::timeout,[=](){
            //停止计时
            timer->stop();
            //销毁计时器
            timer->deleteLater();
            //告诉主场景，返回信号。主场景监听返回信号
            emit this->chooseSceneBack();
        });
        //启动计时器
        timer->start(50);
    });

    //点击关卡开始音效
    QSound *levelSound=new QSound(":/image/TapButtonSound.wav");
    //创建选择关卡的按钮
    for(int i=0;i<20;i++){
        MyPushButton *menuBtn =new MyPushButton(":/image/bill.png");
        menuBtn->setParent(this);
        //设置图片为固定大小
        menuBtn->setFixedSize(this->width()*0.15,this->height()*0.15);
        //设置图标大小
        menuBtn->setIconSize(QSize( menuBtn->width(),menuBtn->width()));
        //移动按钮到指定位置
        menuBtn->move(i%4*120+80,i/4*120+350);
        //使用QLabel显示图片上的文字
        QLabel *label=new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(i%4*120+80,i/4*120+350);
        //监控每个按钮的点击事件
        connect(menuBtn,&QPushButton::clicked,[=](){
            //            qDebug()<<"选择关卡："<<i+1;
            //关卡按钮点击后音效
            levelSound->play();
            //进入游戏场景
            gameScene=new GameScene(i+1);

            //设置为当前场景位置
            gameScene->setGeometry(this->geometry());

            gameScene->show();//显示具体关卡界面
            this->hide();//隐藏选择关卡界面

            //监听具体关卡信号--每个关卡不一样，所以放到场景创建后
            connect(gameScene,&GameScene::chooseSceneBack,[=](){
                //                qDebug()<<"检测信号！";
                //设置为当前场景位置
                this->setGeometry(gameScene->geometry());
                //显示当前页面，删除关卡页面
                this->show();
                delete gameScene;
                gameScene=NULL;
            });

        });
        //设置文字居中
        //如果此处设置剧中，上面移动则不需要偏移
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        //设置字体
        QFont ft;
        ft.setPointSize(12);//设置字体大小
        ft.setBold(true);//加粗
        ft.setFamily("幼圆");//设置字体
        label->setFont(ft);

        //设置鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }


}
//重写绘图事件
void ChooseLevelScene::paintEvent(QPaintEvent *){
    //创建画家
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载背景图片
    pix.load(":/image/background2.png");
    //绘制背景图片
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //绘制背景图标
    pix.load(":/image/title.png");
    //图片缩放
    pix= pix.scaled(pix.width()*0.6,pix.height()*0.6);
    painter.drawPixmap(10,30,pix);//后面画的图层在上面
}
