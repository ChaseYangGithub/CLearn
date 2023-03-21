#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>//文件对话框
#include<QLineEdit>//不包含·智能·提示不提示
#include<QFile>//Qt文件读取
#include<QTextCodec>//编码格式 在Qt6中没有了
#include<QFileInfo>//文件信息类
#include<QDebug>
#include<QDateTime>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击选取文件，弹出文件对话框
    connect(ui->pushButton,&QPushButton::clicked,[=](){//CONFIG+=c++11
        //默认路径是当前项目的构建路径而不是项目文件所在路径！
        QString path=QFileDialog::getOpenFileName(this,"打开文件","../8_1_QtFile/葬花吟.txt");
        //将路径输入到单行文本框中
        ui->lineEdit->setText(path);
        //多行文本放入文本编辑框中
        //编码格式类
        //        QTextCodec *codec= QTextCodec::codecForName("gbk");
        QFile file(path);//参数就是文件读取路径  注意默认格式 UTF-8
        //设置打开方式
        file.open(QIODevice::ReadOnly);
        //读取文件
        QByteArray array=file.readAll();
        //        QByteArray array;
        //        //按行读取
        //        while(!file.atEnd()){
        //             array+=file.readLine();
        //        }
        //将读取数据放入textEdit中
        ui->textEdit->setText(array);//默认方式
        //先转码再读取
        //        ui->textEdit->setText(codec->toUnicode(array));
        //关闭文件
        file.close();

        //        //文件写操作
        //        file.open(QIODevice::Append);//追加方式写操作
        //        file.write("\n山一重，水一重，");
        //        file.close();

        //文件信息类
        QFileInfo info(path);//文件路径
        qDebug()<<"大小："<<info.size()
               <<"文件名称:"<<info.fileName()
              <<"文件路径："<<info.filePath()
             <<"文件类型："<<info.suffix();
        //文件日期  注意包含QDataTime
        qDebug()<<"创建日期："<<info.created().toString("yyyy/MM/dd hh:mm:ss");



    });
}

Widget::~Widget()
{
    delete ui;
}
