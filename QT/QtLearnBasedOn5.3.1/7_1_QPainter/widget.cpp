#include "widget.h"
#include "ui_widget.h"
#include<QPainter>//画家类
#include<QTimer>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击按钮移动图片
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        //如果需要手动调用绘图事件，使用update更新
        posx+=20;
        update();
    });
    //定时器自动实现移动
    QTimer *timer=new QTimer(this);
    //启动定时器
    timer->start(500);
    connect(timer,&QTimer::timeout,[=](){
        posx+=20;
        update();
    });

}
//绘图事件
void Widget::paintEvent(QPaintEvent* ){
    //    //实例化画家对象
    //    QPainter painter(this);//this指定绘图设备
    //    //设置画笔
    //    QPen pen(QColor(126,23,123));
    //    //设置画笔宽度
    //    pen.setWidth(3);
    //    //设置画笔风格
    //    pen.setStyle(Qt::DotLine);
    //    //使用画笔
    //    painter.setPen(pen);

    //    //设置笔刷
    //    QBrush brush(QColor(120,203,123));
    //    //笔刷风格
    //    brush.setStyle(Qt::Dense1Pattern);
    //    //画家使用笔刷
    //    painter.setBrush(brush);


    //    //画线
    //    painter.drawLine(QPoint(0,0),QPoint(100,100));
    //    //画圆 椭圆
    //    painter.drawEllipse(QPoint(100,100),60,60);
    //    //矩形
    //    painter.drawRect(200,100,300,200);
    //    //文字
    //    painter.drawText(QRect(200,400,200,300),"生存还是毁灭");

    //绘图高级事件
    //    QPainter painter(this);
    //    painter.drawEllipse(QPoint(100,50),50,50);
    //    //设置抗锯齿能力 增加抗锯齿效率低点
    //    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    //    painter.drawEllipse(QPoint(200,50),50,50);

    //    //画矩形
    //    painter.drawRect(QRect(20,20,50,50));
    //    //移动画家
    //    painter.translate(100,0);
    //    //保存画家状态
    //    painter.save();
    //    painter.drawRect(QRect(20,20,50,50));
    //    painter.translate(100,0);
    //    //还原画家状态
    //    painter.restore();
    //    painter.drawRect(QRect(20,20,50,50));

    //利用画家直接画资源图片
    QPainter painter(this);
    //设置超出屏幕从0开始
    if(posx>this->width()){
        posx=0;
    }
    painter.drawPixmap(posx,10,QPixmap(":/image/4.jpg"));



}

Widget::~Widget()
{
    delete ui;

}
