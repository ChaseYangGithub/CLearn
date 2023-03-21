#include "smallwidget.h"
#include "ui_smallwidget.h"
#include<QSpinBox>
#include<QSlider>
SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);
    //QSpinBox移动 QSlider跟着移动
    //函数指针： 返回值 作用域 指针名称 参数类型
    void(QSpinBox::*spSignal)(int)=&QSpinBox::valueChanged;
    connect(ui->spinBox,spSignal,ui->horizontalSlider,&QSlider::setValue);
    //QSlider滑动，QSpinBox跟着改变
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}
//设置数值为指定值
void SmallWidget::setNum(int num){
    ui->spinBox->setValue(num);
}

//获取值
int SmallWidget::getNum(){
    return ui->spinBox->value();
}

SmallWidget::~SmallWidget()
{
    delete ui;
}
