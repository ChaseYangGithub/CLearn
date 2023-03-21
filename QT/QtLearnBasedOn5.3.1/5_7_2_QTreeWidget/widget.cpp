#include "widget.h"
#include "ui_widget.h"
#include<QTreeWidget>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //treeWidget

    //设置水平头
    ui->treeWidget
            ->setHeaderLabels(QStringList()<<"英雄"<<"英雄简介");//匿名对象的使用

    //添加顶层节点
    QTreeWidgetItem *liItem=new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *minItem=new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem *zhiItem=new QTreeWidgetItem(QStringList()<<"智力");
    //加载顶层节点
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(minItem);
    ui->treeWidget->addTopLevelItem(zhiItem);

    //追加子节点
    QStringList heroL1;
    heroL1<<"纳兰容若"<<"字性德，天才诗人";
    QTreeWidgetItem *l1=new QTreeWidgetItem(heroL1);
    liItem->addChild(l1);
    QStringList heroL2;
    heroL2<<"仓央嘉措"<<"26代达赖喇叭 转世灵童";
    QTreeWidgetItem *l2=new QTreeWidgetItem(heroL2);
    liItem->addChild(l2);
    QStringList heroM1;
    heroM1<<"东方不败"<<"红颜薄命 ";
    QTreeWidgetItem *M1=new QTreeWidgetItem(heroM1);
    minItem->addChild(M1);

}

Widget::~Widget()
{
    delete ui;
}
