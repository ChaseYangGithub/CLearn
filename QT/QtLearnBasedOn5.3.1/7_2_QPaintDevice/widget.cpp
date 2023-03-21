#include "widget.h"
#include "ui_widget.h"
#include<QPixmap>
#include<QPainter>
#include<QImage>
#include<QPicture>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //    //Pixmap绘图设备  专门为平台做了显示的优化
    //    QPixmap pix(1000,1000);//宽高
    //    //填充背景
    //    pix.fill(Qt::white);
    //    //声明画家
    //    QPainter painter(&pix);
    //    painter.setPen(QPen(Qt::cyan));
    //    painter.drawEllipse(QPoint(100,100),100,100);
    //    //保存-- 此时画出来窗口是没有东西的但是保存文件是存在的
    //    pix.save("D:\\CodingSpace\\Qt\\QtLearnBasedOn5.3.1\\7_2_QPaintDevice\\pix.png");

    //    //QImage作为绘图设备
    //    //宽高 格式
    //    QImage img(300,300,QImage::Format_RGB32);
    //    img.fill(Qt::blue);
    //    QPainter painter(&img);
    //    painter.setPen(Qt::green);
    //    painter.drawEllipse(QPoint(100,100),100,100);
    //    img.save("D:\\CodingSpace\\Qt\\QtLearnBasedOn5.3.1\\7_2_QPaintDevice\\img.png");


    //QPicture作为绘图设备 可以记录和重现绘图指令
    //        QPicture pic;
    //        QPainter painter;
    //        //指定绘图设备，开始画
    //        painter.begin(&pic);
    //        painter.setPen(QPen(Qt::cyan));
    //        painter.drawEllipse(QPoint(100,100),100,100);
    //        //结束绘画
    //        painter.end();
    //        //保存 格式名称随便
    //        pic.save("D:\\CodingSpace\\Qt\\QtLearnBasedOn5.3.1\\7_2_QPaintDevice\\pic.zt");


}


//窗口绘图事件
void Widget::paintEvent(QPaintEvent *){
    //    QPainter painter(this);
    //    //利用QImage对像素进行修改
    //    QImage img;
    //    //加载图片
    //    img.load(":/image/3.jpg");
    //    //修改像素点
    //    for(int i=50;i<100;i++){
    //        for(int j=50;j<100;j++){
    //            //像素点
    //            QRgb value=qRgb(255,0,0);
    //            img.setPixel(i,j,value);
    //        }
    //    }
    //显示图片
    // painter.drawImage(0,0,img);

    QPainter painter(this);
    //重现绘图指令
    QPicture pic;
    pic.load("D:\\CodingSpace\\Qt\\QtLearnBasedOn5.3.1\\7_2_QPaintDevice\\pic.zt");
    painter.drawPicture(0,0,pic);
}

Widget::~Widget()
{
    delete ui;
}
