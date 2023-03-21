#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>//对话框
#include<QDebug>
#include<QMessageBox>//消息对话框
#include<QColorDialog>//颜色对话框
#include<QFileDialog>//文件对话框
#include<QFontDialog>//字体对话框

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //自定义对话框
    //点击新建按钮弹出对话框
    connect(ui->actionNew,&QAction::triggered,[=]{//当前版本下注意添加 CONFIG+=c++11
        //对话框两种分类
        //非模态对话框（可以对其他窗口进行操作）模态（不可以对其他窗口进行操作）

        //模态方式创建
//        QDialog dlg(this);
//        dlg.exec();//模态方式创建
//        dlg.resize(200,100);
//        qDebug()<<"模态对话框信息";//不会显示，因为模态方式创建阻塞后面的代码

        //非模态方式创建
//        QDialog dlg2(this);//使用这种方式创建后show()函数不阻塞，对话框显示，但是函数会立即返回代码继续执行
//        QDialog *dlg2 =new QDialog(this);
//        dlg2->resize(200,100);
//        dlg2-> show();
//        //如果一直点击新建取消但不停止窗口，一直新建对象，可能会导致内存泄漏
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);//关闭窗口时删除属性
//        qDebug()<<"非模态对话框信息";


        //消息对话框
        //错误对话框
//        QMessageBox::critical(this,"critical","错误消息");

        //消息对话框
//        QMessageBox::information(this,"information","消息提示");

        //提问对话框 父类 标题 内容 选项 默认关联值
//        QMessageBox::question(this,"question","提问对话框",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel);
        //判定用户选择的选项
//        if(QMessageBox::Save==QMessageBox::question(this,"question","提问对话框",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel)){
//            qDebug()<<"选择的是save";
//        }else{
//            qDebug()<<"选择的是cancel";
//        }

        //警告对话框
//        QMessageBox::warning(this,"warning","警告信息");

//        //颜色对话框
//        QColor color=QColorDialog::getColor(QColor(255,0,0));
//        qDebug()<<color.red()<<" "<<color.blue()<<" "<<color.green();

//        //文件对话框 打开文件 父类 操作名 默认路径 过滤文件格式
//        QString str=QFileDialog::getOpenFileName(this,"打开","C:\\Users\\yangc\\Desktop\\image","*.jpg");
//        qDebug()<<str;//如果取消返回空字符串，选中文件返回文件路径

        //字体对话框
        bool flag;
        //打开字体 标志  默认字体及字体大小
       QFont qFont=QFontDialog::getFont(&flag,QFont("华文彩云",36));
       qDebug()<<"字体："<<qFont.family().toUtf8().data()//string类型转化为char*
              <<"字号："<<qFont.pointSize()
             <<"加粗："<<qFont.bold()
               <<"斜体："<<qFont.italic();


    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
