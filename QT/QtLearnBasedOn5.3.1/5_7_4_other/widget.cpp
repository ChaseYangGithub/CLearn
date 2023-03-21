#include "widget.h"
#include "ui_widget.h"
#include<QLabel>
#include<QMovie>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //栈控件的使用
    //设置默认定位
    ui->stackedWidget->setCurrentIndex(0);//设置当前索引值
    //按钮1
    connect(ui->stacked1,&QPushButton::clicked,[=](){//CONFIG+=c++11
        ui->stackedWidget->setCurrentIndex(0);//设置当前索引值

    });

    //按钮1
    connect(ui->stacked2,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);//设置当前索引值

    });

    //下拉框
    ui->comboBox->addItem("皮卡");
    ui->comboBox->addItem("房车");
    ui->comboBox->addItem("SUV");
    ui->comboBox->addItem("轿车");
    //点击按钮选中皮卡
    connect(ui->btn_combo1,&QPushButton::clicked,[=](){
        ui->comboBox->setCurrentIndex(0);
        ui->comboBox->setCurrentText("皮卡");//当前内容要有才行
    });

    //Label添加图片
    ui->label_movie->setPixmap(QPixmap(":/image/1.jpg"));
    //添加动图
    QMovie *movie=new QMovie(":/image/gif1.gif");
    ui->label_movie_2->setMovie(movie);
    //播放动图
    movie->start();

}

Widget::~Widget()
{
    delete ui;
}
