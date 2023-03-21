#include "widget.h"
#include "ui_widget.h"
#include<QTableWidget>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //TableWidget控件

    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    //设置行数
    ui->tableWidget->setRowCount(5);
    //设置正文
//    ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));
    //姓名
    QStringList nameList;
    nameList<<"亚瑟"<<"赵云"<<"妲己"<<"杨玉环"<<"嵇康";
//性别
    QList<QString> sexList;
    sexList<<"男"<<"男"<<"女"<<"女"<<"男";


    for(int i=0;i<5;i++){
        int j=0;
        ui->tableWidget->setItem(i,j++,new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,j++,new QTableWidgetItem(sexList[i]));
        //int 转QString
        ui->tableWidget->setItem(i,j++,new QTableWidgetItem(QString::number(i+15)));
    }


}

Widget::~Widget()
{
    delete ui;
}
