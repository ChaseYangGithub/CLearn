#include "myimage.h"
#include<QPushButton>
#include<QPixmap>
#include<QDebug>
#include<QTimer>
//MyImage::MyImage(QWidget *parent) :
//    QPushButton(parent)
//{
//}

//参数代表的是传入的图片的路径
MyImage::MyImage(QString btnImg){
    QPixmap pix;
    //图片加载失败
    if(!pix.load(btnImg)){
        qDebug()<<QString("图片%1加载失败").arg(btnImg);
        return;
    }
    int size=100;
    //重置大小--图片不一致缩小到固定宽度
    pix=pix.scaled(size,pix.height()/(pix.width()/size));
    //设置固定大小--对上面图片截图
    this->setFixedSize(60,60);
    //设置不规则图形无边框
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图片
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));


    //初始化定时器对象
    timer1=new QTimer(this);
    timer2=new QTimer(this);
    //监听正面翻转反面的信号 并翻转图片
    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str;
        //由于开始没有对应资源，使用的自定义图片没有翻转过程，图片不匹配
        if(this->min==1){//1是正面图片
            str=QString(":/image/level (%1).png").arg(this->level);
            this->min++;
        }else if(this->min==8){//翻转后图片
            str= QString(":/image/tuzi.jpg");
            this->min++;
        }else{//翻转过程图片
            str=QString(":/image/Coin000%1.png").arg(this->min++);
        }
        pix.load(str);
        //触发监听
        //        qDebug()<<"接受到正面到反面翻转信号";
        //设置图片属性
        //由于在外部设置了缩放填充图片及其他图片设置，此处不需要调整参数
        //        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        //        this->setIconSize(QSize(pix.width(),pix.height()));
        //翻转完成重置数据
        if(this->min>this->max){
            this->min=1;
            isAnimation=false;//执行动画标志位
            timer1->stop();
        }

        pix.load(str);
    });
    //监听反面翻转正面的信号 并翻转图片
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str;
        //由于开始没有对应资源，使用的自定义图片没有翻转过程，图片不匹配
        if(this->max==8){//1是翻转前图片
            str= QString(":/image/tuzi.jpg");
            this->max--;
        }else if(this->max==1){//翻转后图片
            str=QString(":/image/level (%1).png").arg(this->level);
            this->max--;
        }else{//翻转过程图片
            str=QString(":/image/Coin000%1.png").arg(this->max--);
        }
        pix.load(str);
        //触发监听
        //        qDebug()<<"接受到正面到反面翻转信号";
        //设置图片属性
        //由于在外部设置了缩放填充图片及其他图片设置，此处不需要调整参数
        //        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        //        this->setIconSize(QSize(pix.width(),pix.height()));
        //翻转完成重置数据
        if(this->min>this->max){
            this->max=8;
            isAnimation=false;//执行动画标志位
            timer2->stop();
        }
        pix.load(str);
    });
}

//改变图片标志的方法
void MyImage::changeFlag(){
    if(!this->isAnimation){//动画没有正在执行
        //如果是正面，翻成反面
        if(this->flag){
            //开始正面翻转反面的定时器
            timer1->start(30);
            //        qDebug()<<"触发正面到反面计时";
            isAnimation=true;//执行动画标志位
            this->flag=false;

        }
        //如果是反面，翻成正面
        else{
            //开始正面翻转反面的定时器
            timer2->start(30);
            //        qDebug()<<"触发反面到正面计时";
            isAnimation=true;//执行动画标志位
            this->flag=true;
        }
    }else{
//        qDebug()<<"if判断拦截多次点击信号";
    }

}
//根据标志位判断鼠标按下事件是否有效--与在changeFlag中判断等价
void MyImage::mousePressEvent(QMouseEvent *e){
    if(this->enable||this->isAnimation||this->win){//同时判断是否赢了--但是有问题，其他按键可以触发图片切换
//                qDebug()<<"鼠标按下事件拦截多次点击信号";
        return;
    }else{//执行父类的操作
        QPushButton::mousePressEvent(e);
    }
}
