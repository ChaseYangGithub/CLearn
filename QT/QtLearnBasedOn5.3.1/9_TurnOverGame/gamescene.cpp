#include "gamescene.h"
#include<QDebug>
#include<QMenuBar>
#include<QPainter>
#include "mypushbutton.h"
#include<QTimer>
#include<QLabel>
#include<QFont>
#include "myimage.h"
#include "dataconfig.h"
#include<QPropertyAnimation>//动画
#include<QSound>
//GameScene::GameScene(QWidget *parent) :
//    QMainWindow(parent)
//{
//}

GameScene::GameScene(int levelNum){
    this->levelIndex=levelNum;
    //    QString str=QString("游戏关卡：%1").arg(levelNum);
    //    qDebug()<<str;

    //初始化游戏场景
    //设置固定大小
    this->setFixedSize(600,1020);
    //设置icon 每一关图片不一样
    this->setWindowIcon(QPixmap(QString(":/image/level (%1).png").arg(this->levelIndex)));
    //设置标题
    this->setWindowTitle(QString("翻转图片第%1关").arg(this->levelIndex));

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
        //                qDebug()<<"具体关卡点击返回按钮";
        //延时操作
        QTimer *timer=new QTimer(this);
        //延时信号检测
        connect(timer,&QTimer::timeout,[=](){
            //停止计时
            timer->stop();
            //销毁计时器
            timer->deleteLater();
            //告诉关卡场景，返回信号。关卡场景监听返回信号
            //              qDebug()<<"发出信号！";
            emit this->chooseSceneBack();;
        });
        //启动计时器
        timer->start(50);
    });

    //实现显示关卡号
    QLabel *label=new QLabel(this);//也可先无参然后setParent this
    //设置字体和大小
    QFont ft;
    ft.setPointSize(22);//字体大小
    ft.setFamily("幼圆");
    ft.setBold(true);//加粗
    //设置字体
    label->setFont(ft);
    //设置内容
    label->setText(QString("Level:%1").arg(this->levelIndex));
    //    //移动位置
    //    label->move(20,this->height()-label->height());
    //设置大小 位置 宽高
    label->setGeometry(20,this->height()-50,200,50);

    //初始化每关的数据
    dataConfig config;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            this->gameArray[i][j]=config.mData[this->levelIndex][i][j];
            //            qDebug()<<gameArray[i][j]; //数据无误  数据是先列后行的
        }
    }

    //设置胜利图片
    QLabel *winLabel=new QLabel;
    QPixmap pixWin;
    pixWin.load(":/image/LevelCompletedDialogBg.png");//设置图片
    winLabel->setGeometry(0,0,pixWin.width(),pixWin.height());//设置位置及大小
    winLabel->setPixmap(pixWin);
    winLabel->setParent(this);
    winLabel->move((this->width()-pixWin.width())*0.5,-pixWin.height());//移动到水平居中，垂直在界面外
    //翻转金币音效
    QSound *coinSound=new QSound(":/image/ConFlipSound.wav");
    //点击关卡开始音效
    QSound *winSound=new QSound(":/image/LevelWinSound.wav");
    //设置默认背景，图片 点击图片
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            //绘制背景图片
            QPixmap pix=QPixmap(":/image/backPure3.png");
            //图片缩放
            //            pix.scaled(pix.width()*0.1,pix.height()*0.1);
            QLabel *label=new QLabel(this);
            label->setPixmap(pix);
            //设置大小 位置 宽高
            label->setGeometry(0,0,pix.width()*0.5,pix.height()*0.5);
            //设置缩放填充图片
            label->setScaledContents(true);
            label->move(80+i*100,j*100+330);

            //创建图片
            //设置关卡图片数据
            QString str;
            if(this->gameArray[i][j]==1){//1是翻转后图片
                str=QString(":/image/level (%1).png").arg(this->levelIndex);
            }else{//翻转前图片

                str= QString(":/image/tuzi.jpg");

            }

            MyImage *image=new MyImage(str);
            image->setParent(this);
            image->move(115+i*100,j*100+345);

            //金币属性赋值
            image->x=i;
            image->y=j;
            image->level=this->levelIndex;//存储对应图片位序
            image->flag=this->gameArray[i][j];//1 正面 0反面

            //图片放到图片二维数组指针中，便于后期维护
            this->imagePoint[i][j]=image;
            //点击金币，进行翻转
            connect(image,&MyImage::clicked,[=](){
                //禁用所有按钮
                for(int a=0;a<4;a++){
                    for(int b=0;b<4;b++){
                        this->imagePoint[a][b]->enable=true;
                    }
                }
                //翻转金币音效
                coinSound->play();
                image->changeFlag();
                //修改数据，便于后续操作
                this->gameArray[i][j]=this->gameArray[i][j]==0?1:0;
                //周围翻转,延时
                //        QTimer ::singleShot(500,this,[=]{}); 5.3不支持这种写法
                //延时周围翻转
                QTimer* t = new QTimer(this);
                connect(t,&QTimer::timeout,[=](){
                    //右
                    if(image->x+1<=3){
                        this->imagePoint[image->x+1][image->y]->changeFlag();
                        this->gameArray[image->x+1][image->y]=(this->gameArray[image->x+1][image->y]==0?1:0);

                    }
                    //左
                    if(image->x-1>=0){
                        this->imagePoint[image->x-1][image->y]->changeFlag();
                        this->gameArray[image->x-1][image->y]=(this->gameArray[image->x-1][image->y]==0?1:0);
                    }
                    //上
                    if(image->y+1<=3){
                        this->imagePoint[image->x][image->y+1]->changeFlag();
                        this->gameArray[image->x][image->y+1]=(this->gameArray[image->x][image->y+1]==0?1:0);
                    }

                    //下
                    if(image->y-1>=0){
                        this->imagePoint[i][j-1]->changeFlag();
                        this->imagePoint[image->x][image->y-1]->changeFlag();
                        this->gameArray[image->x][image->y-1]=(this->gameArray[image->x][image->y-1]==0?1:0);
                    }
                    t->stop();//停止计时
                    t->deleteLater();//删除对象
                    //结束禁用按钮
                    for(int a=0;a<4;a++){
                        for(int b=0;b<4;b++){
                            this->imagePoint[a][b]->enable=false;
                        }
                    }
                    //翻转完成判断是否胜利--注意要放在计时器内部，因为放在外部会导致先执行判断
                    if(this->isWin()){
                        image->win=true;//将赢了标志改为true
                        //                        qDebug()<<"胜利";
                        //禁用所有按钮
                        for(int a=0;a<4;a++){
                            for(int b=0;b<4;b++){
                                this->imagePoint[a][b]->enable=true;
                            }
                        }
                        //胜利音效

                        winSound->play();
                        //移动胜利图片
                        QPropertyAnimation *animation=new QPropertyAnimation(winLabel,"geometry");//看Qt助手介绍
                        //设置时间间隔
                        animation->setDuration(1000);
                        //设置开始值
                        animation->setStartValue(QRect((this->width()-pixWin.width())*0.5,0,winLabel->width(),winLabel->height()));
                        //设置结束位置
                        animation->setEndValue(QRect((this->width()-pixWin.width())*0.5,200,winLabel->width(),winLabel->height()));
                        //设置缓和曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        //开始动画
                        animation->start();
                    }

                });
                t->start(300);//开始计时


            });
        }
    }


    //设置下方图片
    QLabel *label2=new QLabel(this);
    QPixmap pix2=QPixmap(QString(":/image/level (%1).png").arg(this->levelIndex));
    pix2=pix2.scaled(200,pix2.height()/(pix2.width()/200));
    label2->setPixmap(pix2);
    //设置大小 位置 宽高
    label2->setGeometry(0,0,pix2.width(),pix2.height());
    label2->move(200,800);


}


//判断是否胜利
bool GameScene::isWin(){
    //    for(int x=0;x<4;x++){
    //        for(int y=0;y<4;y++){
    //            qDebug()<<this->gameArray[x][y];
    //        }
    //    }
    for(int x=0;x<4;x++){
        for(int y=0;y<4;y++){

            if(this->gameArray[x][y]==0){
                qDebug()<<QString("x=%1,y=%2").arg(x).arg(y);
                return false;
            }
        }
    }

    return true;
}

//重写paintEvent事件
void GameScene::paintEvent(QPaintEvent *){
    //创建画家
    QPainter painter(this);
    //创建Pixmap对象
    QPixmap pix;
    //加载背景图片
    pix.load(":/image/background3.jpg");
    //绘制背景图片
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //绘制背景图标
    pix.load(":/image/title.png");
    //图片缩放
    pix= pix.scaled(pix.width()*0.6,pix.height()*0.6);
    painter.drawPixmap(10,30,pix);//后面画的图层在上面

}


