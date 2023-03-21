#include "mywidget.h"
#include<QPushButton>//按钮控件的头文件
#include<QDebug>//用于控制台输出
#include "mypushbutton.h"
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)//初始化列表，相关知识点见C++核心4.2.6
{
    //方式1
    //创建一个按钮
    QPushButton *btn=new QPushButton();//不能用局部变量空间太小
    //btn->show();//show是以顶层方式弹出窗口控件
    //让btn对象依赖在myWidget中
    btn->setParent(this);
    //显示文本
    btn->setText("第一个按钮");

    //方式2 按照控件大小来创建窗口
    QPushButton* btn2=new QPushButton("第二个按钮",this);
    //移动btn2按钮
    btn2->move(100,100);//宽 高。坐标原点在左上角
    //按钮重置大小
    btn2->resize(100,100);
    //重置窗口大小--用户对于窗口可拖拽改变大小
    resize(600,400);//宽 高
    //设置固定的窗口大小
    setFixedSize(600,400);
    //设置窗口标题
    setWindowTitle("第一个窗口");

    //我的按钮控件--测试对象模型自动销毁
    //创建自己的对象
    MyPushButton *myPush=new MyPushButton();
    myPush->setText("我自己的按钮");
    myPush->move(300,0);
    myPush->setParent(this);

    //点击按钮关闭窗口
    //参数 信号的发送者 发送的信号 信号接收者 处理的槽函数
    //clicked点击时 close操作为关闭窗口
    connect(myPush,&MyPushButton::clicked,this,&myWidget::close);
    connect(myPush,&QPushButton::clicked,this,&myWidget::close);


}

myWidget::~myWidget()
{
    qDebug()<<"自动析构";
}
