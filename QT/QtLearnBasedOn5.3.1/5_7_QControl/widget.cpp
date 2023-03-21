#include "widget.h"
#include "ui_widget.h"
#include<QRadioButton>
#include<QDebug>
#include<QCheckBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置单选按钮，默认选中
    ui->rBtnMan->setChecked(true);//rBtnMan为对应单选按钮的类名
    //选中女后 打印信息
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){//注意包含lambda表达式
        qDebug()<<"选中了女";
    });
    //多选按钮 选中变化 2选中 1是半选（可以理解为子项目没有选完） 0未选中
    connect(ui->checkBox_3,&QCheckBox::stateChanged,[=](int state){
        qDebug()<<state;
    });

    //QListWidget
    //利用ListWidget写诗
    //单行方式
    QListWidgetItem *item =new QListWidgetItem("静夜思");
    //将文字放到ListWidget控件中
    ui->listWidget->addItem(item);
    //设置水平居中
    item->setTextAlignment(Qt::AlignHCenter);

    //多行方式
    //QStringList
    QStringList list;
    list<<"床前明月光"<<"疑是地上霜"<<"举头望明月"<<"低头思故乡";//每个一行
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}
