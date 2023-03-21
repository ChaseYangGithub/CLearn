#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //可以通过ui找到ui文件中所有的控件
    //设置新建的图标资源--注意路径中不要有中文 --绝对路径方式
//    ui->actionNew->setIcon(QIcon("C:/Users/yangc/Desktop/image/4.jpg"));
    //使用Qt资源：":+前缀名+文件名"
    ui->actionNew->setIcon(QIcon(":/image/1.jpg"));
    ui->actionOpen->setIcon(QIcon(":/image/2.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
